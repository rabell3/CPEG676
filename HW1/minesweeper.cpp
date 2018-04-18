#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

enum DIFFICULTY { Easy, Medium, Hard };

class MinesweepGameboard
{
    public:
        MinesweepGameboard();
        void createGameboard(int x, int y, int mines, DIFFICULTY level);  // should meet requirement 1
        int getXdim(int x) { return dim_x; }
        int getydim(int y) { return dim_y; }
        void printGameboard();
        char* getDifficulty();
        ~MinesweepGameboard();

    private:
//        void setDimensions(int x, int y);
//        void setMines(int mines);
        DIFFICULTY difficulty;
        int dim_x;
        int dim_y;
        int cMines;
};

// Constructor
MinesweepGameboard::MinesweepGameboard()
{
    cout << "Minesweeper object initialized.\n";
    dim_x = 0;
    dim_y = 0;
    cMines = 0;
    difficulty = Easy;
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
    dim_x = x;
    dim_y = y;
}

void MinesweepGameboard::setMines(int mines)
{
    cMines = mines;
}
*/

void MinesweepGameboard::createGameboard(int width, int height, int mines, DIFFICULTY level)
{
    cout << "Gameboard created.\n";
    dim_x = width;
    dim_y = height;
    cMines = mines;
    difficulty = level;
}
void MinesweepGameboard::printGameboard()
{
    printf("Your gameboard is: %d wide, %d high, with %d mines, an %s gameboard.\n", dim_x, dim_y, cMines, getDifficulty());
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

    printf("HW1: CLI Minesweeper - RABIII\n");
    MinesweepGameboard msGame;

    printf("Choose level of difficulty (E)asy, (M)edium, (H)ard): ");
    cin >> level;
    switch (level)
    {
        case 'E':
            cout << "Generating an Easy gameboard...\n";
            msGame.createGameboard(10,6,10,Easy);
            break;
        case 'M':
            cout << "Generating a Medium gameboard...\n";
            msGame.createGameboard(20,12,20,Medium);
            break;
        case 'H':
            cout << "Generating a Difficult gameboard...\n";
            msGame.createGameboard(30,18,30,Hard);
            break;
        default:
            cout << "This shouldn't happen\n";
            break;
    }

    msGame.printGameboard();
    return 0;
}