#pragma once


void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	int n = matrixSize;
	int swapSpace;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			swapSpace = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = swapSpace;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n/2; j++)
		{
			swapSpace = matrix[i][j];
			matrix[i][j] = matrix[i][n-j];
			matrix[i][n-j] = swapSpace;
		}
	}
}