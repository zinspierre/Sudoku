#pragma once
#include <iostream>
#include <boost/timer.hpp>
#include <set>
#include <queue>
#include <fstream>
#include <string>
#include "Subject.h"

#define SIZE 9
#define B_HEIGHT 3
#define B_WIDTH 3

/**
	i => lines : 0 - 8
	j => columns : 0 - 8
**/

struct Case
{
	int i;
	int j;
};

class SudokuSolver : public Subject
{
private:
	int grid[SIZE][SIZE];

    bool isPresentLine(int v, int l);
    bool isPresentCol(int v, int c);
    bool isPresentBloc(int v, int x, int y);

    //simple recursice fct to solve sudoku (use isPresentLine, isPresentCol and isPresentBloc)
    //test all number (1->9)
    bool isValid(int position);



    //First little improvement : possibility
    //return vector containing every possibilies of a case, input i, j
    std::vector<int> possibility(int i, int j);

    //optim version of isValid()
    //test only possible number (not 1-9)
    bool optIsValid(int position);



    //Second little improvement : possibility + queue with best next case to solve
    std::queue<Case> file;
    //return the next void case (start up-left) : for megaOptIsValid
    int nextVoidCase();
    //initialize queue push each void case
    void initQueue();
    //optim version of optIsValid()
    //use a queue to put every empty case
    //not sure very useful
    bool megaOptIsValid(int position);



    //fill _foundPositions with positions of non-null numbers
    void foundNumbers(std::vector<std::vector<int>>& _foundPositions);



    //******************************************************************************************************************
    //FUNCTIONS NOT USED

    //check if line n is correct (no doublon 1<=x<=9)
    bool checkLine(int n);

    //same for column
    bool checkColumn(int n);

    //check square from numero of square
    bool checkSquare(int numero);
    //check if area is OK (no doublon and 1<=x<=9) i,j input
    bool checkArea(int _x, int _y);

    //check if grid contain empty case (= 0)
    bool hasZero();

    //return number of zero in an area i,j input
    int countAreaZero(int _x, int _y);

    //return number of line containing0 most number of zero
    int bestLine();

    //return column number containing most nuymber of zero
    int bestColumn();

    //return numero of square containing most number of zero
    int bestSquare();
    //******************************************************************************************************************



public:
    SudokuSolver();

    //solve sudoku
    bool solve();
    //unveil one number
    void hideExceptOne();
    //check if grid is complete (maybe not valid, but no zero)
    bool isFilled() const;


    //IMPORT EXPORT

    //import grid from file
    void importGridFromFile(const std::string &_filename);

    //import grid from array int[GRID][GRID]
    void importGrid(int _grid[SIZE][SIZE]);

    //print grid
    void print();

    int getValue(int i, int j){
        return grid[i][j];
    }

};



