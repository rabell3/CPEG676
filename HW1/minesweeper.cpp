#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

enum DIFFICULTY { Easy, Medium, Hard };
struct cellStatus
{
    unsigned short xCoord;
    unsigned short yCoord;
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
        unsigned short getWidth(unsigned short x) { return width; }
        unsigned short getHeight(unsigned short y) { return height; }
        cellStatus getXYval(unsigned short x, unsigned short y);
        void printGameboard();
        void printGameboardStats();
        char* getDifficulty();
        bool isOpen();
        bool isFlagged();
        bool hasMine();
        int getNeighbors();

    private:
//        void setDimensions(int x, int y);
        unsigned short setMines(DIFFICULTY difficulty);
        DIFFICULTY difficulty;
        unsigned short width;
        unsigned short height;
        unsigned short cMines;
        int gameArray[0][0];
};

// Constructor
MinesweepGameboard::MinesweepGameboard()
{
    cout << "Basic Minesweeper object initialized.\n";
    width = 0;
    height = 0;
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

/*
void MinesweepGameboard::setDimensions(int x, int y)
{
    cout << "Setting dimensions of gameboard...\n";
    width = x;
    height = y;
}
*/
unsigned short MinesweepGameboard::setMines(DIFFICULTY difficulty)
{
    srand (time(NULL));
    unsigned short easyMines = rand() % 10 + 1;
    unsigned short mediumMines = rand() % 20 + 11;
    unsigned short hardMines = rand() % 30 + 21;

    switch (difficulty)
    {
        case Easy:
            return easyMines;
            break;
        case Medium:
            return mediumMines;
            break;
        case Hard:
            return hardMines;
            break;
        default:
            // This shouldn't happen
            return 0;
            break;
    }
}

void MinesweepGameboard::createGameboard(unsigned short inwidth, unsigned short inheight, DIFFICULTY inlevel)
{
    cout << "Gameboard created.\n";
    width = inwidth;
    height = inheight;
    difficulty = inlevel;
    cMines = setMines(difficulty);
    unsigned short gameArray[width][height];

    for (int i=0; i<height; i++)
        for (int j=0; j<width; j++)
        {
            gameArray[i][j]=(i+1)*(j+1);
        }
}
void MinesweepGameboard::printGameboardStats()
{
    printf("Your gameboard is: %d wide, %d high, with %d mines, an %s gameboard.\n", width, height, cMines, getDifficulty());
    printf("gameArray is: %d bytes\n",sizeof(gameArray));
}
void MinesweepGameboard::printGameboard()
{
    printGameboardStats();

    for (int i=0; i<height; i++)
        for (int j=0; j<width; j++)
        {
//            int val = getXYval(i,j);
//            printf("Val: %d", val);
            printf("Hello!\n");
        }
    printf("\n");
    return;
}

cellStatus MinesweepGameboard::getXYval(unsigned short x, unsigned short y)
{ 
    return { x, y, isOpen(), isFlagged(), hasMine(), getNeighbors() };
}

bool MinesweepGameboard::isOpen()
{
    return true;
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
    return 0;
}