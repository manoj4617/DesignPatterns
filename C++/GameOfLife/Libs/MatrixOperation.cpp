#include "../Headers/Matrix.hpp"


void Matrix::BuildInitialMatrix(std::vector<std::pair<int,int>> liveCellsCoord){
   for(const auto& coord : liveCellsCoord){
        matrix[coord.first][coord.second] = 1;
   }
}

void Matrix::UpdateMatrix(){
    //Create a copy of the original matrix
    std::vector<std::vector<int>> originalMatrix = matrix;

    int rows = matrix.size();
    int columns = matrix[0].size();

    for(int row=0;row<rows;++row){
        for(int col=0;col<columns;++col){
            int liveNeighbors = 0;

            //Itereating over the neighboring cells
            for(int i=-1;i<=1;++i){
                for(int j=-1;j<=1;++j){
                    if(i == 0 && j == 0){
                        continue;
                    }

                    int neighborRow = row + i;
                    int neighborCol = col + j;

                    if(neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < columns){
                        liveNeighbors += originalMatrix[neighborRow][neighborCol];
                    }
                }
            }

            //Game of life rules
            if(originalMatrix[row][col] == 1){
                //if the cell is alive

                //cell dies due to underpopulation or over population
                if(liveNeighbors < 2 || liveNeighbors > 3){
                    matrix[row][col] = 0;
                }
            }
            else{
                //cell is dead
                if(liveNeighbors == 3 || liveNeighbors == 2){
                    //Cell becomes live duw to under population
                    matrix[row][col] = 1;
                }
            }
        }
    }
}

void Matrix::PrintMatrix(){
    std::cout << "\n****************************************\n\n";
    for(int i=0;i<rows;++i){
        std::cout << "\t\t";
        for(int j=0;j<columns;++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
