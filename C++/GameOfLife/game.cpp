// GameOfLife.cpp
//
#include "Headers/Matrix.h"


int main()
{
	std::cout << "*************** WELCOME TO THE GAME OF LIFE ***************" << "\n\n\n";
	
	std::cout << "Enter the number of rows and columns for the grid\n";
	std::cin >> rows >> columns;

	if (rows > MAX_ROWS || columns > MAX_COLS) {
		std::cerr << "\t\t\tGrid size cannot be exceed 1000*1000\n";
	}

	//print the matrix with 0 as all elements
	//ask for user input to set the cell to live
	//run the game

	return 0;
}
