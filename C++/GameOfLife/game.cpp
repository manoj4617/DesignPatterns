// GameOfLife.cpp
//
#include "Headers/Matrix.hpp"


int main()
{
	int input_rows;
	int input_columns;

	int xCoordLiveCell = 0;
	int yCoordLiveCell = 0;
	int generations;
	std::vector<std::pair<int,int>> liveCellCoord;

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
	
	std::cout << "\t\tEmpty Grid\n\n";
	newMatrix->PrintMatrix();

	std::cout << "\n\nEnter row and column coordinates (separated by a space), or enter -1 to stop:\n\n";

	//ask for user input to set the cell to live
	while(std::cin >> xCoordLiveCell >> yCoordLiveCell){
		if(xCoordLiveCell == -1 || yCoordLiveCell == -1){
			break;
		}
		liveCellCoord.push_back(std::make_pair(xCoordLiveCell, yCoordLiveCell));
		std::cout << "Enter next coordinates, or enter -1 to stop:\n";
	}
	newMatrix->BuildInitialMatrix(liveCellCoord);
	newMatrix->PrintMatrix();

	std::cout << "Enter the number of generations you want the game to run: \n\n";
	std::cin >> generations;

	while(generations--){
		newMatrix->UpdateMatrix();
		newMatrix->PrintMatrix();
		system("clear");
	}
	//run the game
	
	return 0;
}
