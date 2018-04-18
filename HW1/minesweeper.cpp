#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

enum DIFFICULTY { Easy, Medium, Difficult };

class MinesweepGameboard
{
    public:
        MinesweepGameboard();
        void createGameboard(int x, int y, int mines, DIFFICULTY level);
        void getDimensions(int x, int y);
        ~MinesweepGameboard();

    private:
        void setDimensions(int x, int y);
        void setMines(int mines);
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

void MinesweepGameboard::createGameboard(int x, int y, int mines, DIFFICULTY level)
{
    cout << "Gameboard created.\n";
    dim_x = x;
    dim_y = y;
    cMines = mines;
    difficulty = level;
}

main(){
    printf("HW1: CLI Minesweeper - RABIII\n");
    MinesweepGameboard msGame;
    msGame.createGameboard(10,20,10,Easy);
    return 0;
}