#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <curses.h>

using namespace std;

enum DIFFICULTY { Easy, Medium, Hard };
//enum mineStatus { mine, empty };
struct Cell
{
    //unsigned short xCoord;
    //unsigned short yCoord;
    bool isOpened = false;
    bool hasFlag = false;
    bool hasMine = false;
    unsigned short neighborMines;
};

class MinesweepGameboard
{
    public:
        MinesweepGameboard();
        MinesweepGameboard(unsigned short x, unsigned short y, DIFFICULTY level);
        ~MinesweepGameboard();
        void createGameboard(unsigned short x, unsigned short y, DIFFICULTY level);  // should meet requirement 1
        unsigned short getWidth(unsigned short x) { return mapWidth; }
        unsigned short getHeight(unsigned short y) { return mapHeight; }
        Cell getCell(unsigned short x, unsigned short y);
        void printGameboard();
        void printGameboardStats();
        char* getDifficulty();
        bool isOpen(unsigned short x, unsigned short y);
        void toggleFlag(unsigned short x, unsigned short y);
        bool hasFlag(unsigned short x, unsigned short y);
        bool hasMine(unsigned short x, unsigned short y);
        int getNeighbors();
        int countMines();

    private:
//        void setDimensions(int x, int y);
        unsigned short setMines(DIFFICULTY difficulty);
        void setMap();
        DIFFICULTY difficulty;
        unsigned short mapWidth;
        unsigned short mapHeight;
        unsigned short cMines;
        Cell gameArray[0][0];
};

// Constructor
MinesweepGameboard::MinesweepGameboard()
{
    cout << "Basic Minesweeper object initialized.\n";
    mapWidth = 0;
    mapHeight = 0;
    cMines = 0;
    difficulty = Easy;
}

// Constructor
MinesweepGameboard::MinesweepGameboard(unsigned short x, unsigned short y, DIFFICULTY level)
{
    createGameboard(x, y, level);
    cout << "Proper Minesweeper object initialized.\n";
}

// Destructor
MinesweepGameboard::~MinesweepGameboard()
{
    cout << "Minesweeper object deleted.\n";
}

int MinesweepGameboard::countMines()
{
    int minecount=0;
    for (int i=0; i<mapHeight; i++)
    {
        for (int j=0; j<mapWidth; j++)
        {
            if (hasMine(i,j)) { minecount++; }
        }
    }
    printf("Minecount: %d",minecount);
    return minecount;
}
unsigned short MinesweepGameboard::setMines(DIFFICULTY difficulty)
{
    srand (time(NULL));
    unsigned short easyMines = rand() % 10 + 1;
    unsigned short mediumMines = rand() % 20 + 11;
    unsigned short hardMines = rand() % 30 + 21;

    switch (difficulty)
    {
        case Easy:
            // Generate Easy minefield
            return easyMines;
            break;
        case Medium:
            // Generate Medium minefield
            return mediumMines;
            break;
        case Hard:
            // Generate Hard minefield
            return hardMines;
            break;
        default:
            // This shouldn't happen
            return 0;
            break;
    }
}

void MinesweepGameboard::setMap()
{   // Setting mines on the map
    cout << "Setting mines on gameboard...\n";
    srand (time(NULL));
    Cell myCell;
    int minesSet = 0;
/*    while (minesSet < cMines) {
        int rand_X = rand() % mapWidth + 0;
        int rand_Y = rand() % mapHeight + 0;
        
        myCell = gameArray[rand_X][rand_Y];
        if (myCell.hasMine == false) { myCell.hasMine = true; }
        minesSet++;
//        printf("mines: %d\n", minesSet);
//        printf("%d.%d+", rand_X, rand_Y);
    }*/
    myCell = gameArray[2][2];
    myCell.hasMine = true;
}

void MinesweepGameboard::createGameboard(unsigned short width, unsigned short height, DIFFICULTY indifficulty)
{
    cout << "Gameboard created.\n";
    mapWidth = width;
    mapHeight = height;
    difficulty = indifficulty;

    unsigned short gameArray[width][height];
    cMines = setMines(difficulty);
    setMap();
}
void MinesweepGameboard::printGameboardStats()
{
    printf("Your gameboard is: %d wide, %d high, with %d mines, an %s gameboard.\n", mapWidth, mapHeight, cMines, getDifficulty());
    printf("Gameboard is: %d bytes\n",sizeof(*this));
}
void MinesweepGameboard::printGameboard()
{
    printGameboardStats();
    for (int j=0; j<mapWidth; j++) { printf(" %d", j);}
    printf("\n\u2500");
    for (int j=0; j<2*mapWidth; j++) { printf("\u2500");}
//    printf("\n-------------------------------------------\n");
    printf("\n");
    for (int i=0; i<mapHeight; i++)
    {
        printf("\u2502");
        for (int j=0; j<mapWidth; j++)
        {
            Cell cellVal = getCell(i,j);
            if (cellVal.hasMine) {
                printf("*");
            }
            else printf(" ");
//            printf("%d", int(cellVal.hasMine));
            printf("\u2502");
        }
    printf("\n\u2500");
    for (int j=0; j<2*mapWidth; j++) { printf("\u2500");}
    printf("\n");
//    printf("\n-------------------------------------------\n");
    }
    return;
}

bool MinesweepGameboard::hasMine(unsigned short x, unsigned short y)
{   // Determine if cell has Mine
    Cell myCell = gameArray[x][y];
//    Cell result = getCell(x,y);
    if (myCell.hasMine == true) {
        return true;
    }
    else return false;
}

bool MinesweepGameboard::isOpen(unsigned short x, unsigned short y)
{   // Determine if cell has been opened
    Cell myCell = gameArray[x][y];
//    Cell result = getCell(x,y);
    if (myCell.isOpened == true) {
        return true;
    }
    else return false;
}

void MinesweepGameboard::toggleFlag(unsigned short x, unsigned short y)
{   // Toggle cell open status
    Cell myCell = gameArray[x][y];
    if ( myCell.hasFlag == true )
    {
        myCell.hasFlag = false;
    }
/*
    Cell result = getCell(x,y);
    if (result.isOpened = true) {
    }
*/
}

bool MinesweepGameboard::hasFlag(unsigned short x, unsigned short y)
{   // Determine if cell has flag
    Cell myCell = gameArray[x][y];
//    Cell result = getCell(x,y);
    if (myCell.hasFlag = true) {
        return true;
    }
    else return false;
}

Cell MinesweepGameboard::getCell(unsigned short x, unsigned short y)
{   // Get Cell data
//    return gameArray[x][y];
//    return { x, y, isOpen(), isFlagged(), hasMine(), getNeighbors() };
    Cell rtnCell;
    rtnCell.hasFlag = this->hasFlag(x,y);
    rtnCell.hasMine = this->hasMine(x,y);
    rtnCell.isOpened = this->isOpen(x,y);
//    rtnCell.neighborMines = this->getNeighbors();
    return rtnCell;
}

char* MinesweepGameboard::getDifficulty()
{
    switch (difficulty)
    {
        case Easy:
            return "Easy";
            break;
        case Medium:
            return "Medium";
            break;
        case Hard:
            return "Hard";
            break;
        default:
            // This shouldn't happen
            return "broke";
            break;
    }
}

main(){
//    initscr();  // Disabled for now
    char level;
    unsigned short thisX=0, thisY=0, thisMines=0;
    DIFFICULTY thisDifficulty;


    printf("HW1: CLI Minesweeper - RABIII\n");
    printf("Choose level of difficulty (E)asy, (M)edium, (H)ard): ");
    cin >> level;
    switch (level)
    {
        case 'E':
            cout << "Generating an Easy gameboard...\n";
            thisX = 10;
            thisY = 6;
            thisMines = 10;
            thisDifficulty = Easy;
            break;
        case 'M':
            cout << "Generating a Medium gameboard...\n";
            thisX = 20;
            thisY = 12;
            thisMines = 20;
            thisDifficulty = Medium;
            break;
        case 'H':
            cout << "Generating a Difficult gameboard...\n";
            thisX = 30;
            thisY = 18;
            thisMines = 30;
            thisDifficulty = Hard;
            break;
        default:
            cout << "This shouldn't happen\n";
            break;
    }
    MinesweepGameboard msGame(thisX, thisY, thisDifficulty);
    msGame.printGameboard();
    int blah = msGame.countMines();
//    endwin(); // Disabled for now.
    return 0;
}