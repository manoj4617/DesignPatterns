// GameOfLife.cpp
//
#include "Headers/Matrix.hpp"


int main()
{
	int input_rows;
	int input_columns;
	std::cout << "*************** WELCOME TO THE GAME OF LIFE ***************" << "\n\n\n";
	

	std::cout << "Enter the number of rows and columns for the grid\n";

	do{
		std::cin >> input_rows >> input_columns;
		
		if (input_rows > MAX_ROWS || input_columns > MAX_COLS) {
			std::cerr << "\t\t\tGrid size cannot be exceed 1000x1000\n";
			std::cout << "\t\t\tEnter the grid size again..\n";
		}
	}while(input_columns > MAX_COLS || input_rows > MAX_ROWS);

	std::unique_ptr<Matrix> newMatrix = std::make_unique<Matrix>(input_rows, input_columns);

	newMatrix->BuildInitialMatrix();
	std::cout << "\t\tEmpty Grid\n\n";
	newMatrix->PrintMatrix();



	//ask for user input to set the cell to live
	//run the game

	return 0;
}
