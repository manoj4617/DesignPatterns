#include "../Headers/Matrix.hpp"


void Matrix::BuildInitialMatrix(){
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = 0;
		}
	}
}

void Matrix::UpdateMatrix(){

}

void Matrix::PrintMatrix(){
    for(int i=0;i<rows;++i){
        for(int j=0;j<columns;++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
