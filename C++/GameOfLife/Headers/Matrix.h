#pragma once

#include "GameOfLife.h"

class Matrix {

private:
	std::vector<std::vector<int>> matrix;
	int rows;
	int columns;

public:
	Matrix(std::vector<std::vector<int>>& _matrix,
		int _rows,
		int _cols)
	{
		matrix = _matrix;
		rows = _rows;
		columns = _cols;
	}

	virtual void UpdateMatrix(std::vector<std::vector<int>>& _matrix) = 0;
	virtual void BuildInitialMatrix(std::vector<std::vector<int>>& _matrix) = 0;

};
