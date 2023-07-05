#pragma once

#include "GameOfLife.hpp"


class Matrix {

private:
	std::vector<std::vector<int>> matrix;
	int rows;
	int columns;

public:
	Matrix(int &_rows,int &_cols){
		matrix.resize(_rows, std::vector<int>(_cols, 0));		
		rows = _rows;
		columns = _cols;
	}

	void UpdateMatrix();
	void BuildInitialMatrix();
	void PrintMatrix();

};
