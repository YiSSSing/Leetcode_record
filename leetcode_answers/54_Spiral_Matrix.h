#pragma once
#include <corecrt_malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
	int m = matrixSize;
	int n = *matrixColSize;
	int size = m * n;
	*returnSize = size;

	int* result = (int*)malloc(size * sizeof(int));
	int rowLeft = 0, rowRight = n - 1;
	int colUp = 0, colDown = m - 1;

	int index = 0;
	while (index < size)
	{
		for (int i = rowLeft; i <= rowRight; i++) result[index++] = matrix[colUp][i];
		for (int i = colUp + 1; i <= colDown; i++) result[index++] = matrix[i][rowRight];
		if (index >= size) break;
		for (int i = rowRight - 1; i >= rowLeft; i--) result[index++] = matrix[colDown][i];
		for (int i = colDown - 1; i >= colUp + 1; i--) result[index++] = matrix[i][rowLeft];
		rowLeft++;
		rowRight--;
		colUp++;
		colDown--;
	}
	return result;
}