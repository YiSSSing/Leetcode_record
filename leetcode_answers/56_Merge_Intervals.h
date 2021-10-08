#pragma once
#include <corecrt_malloc.h>


void mergeSortRecursive(int** arr, int start, int end)
{
	if (start >= end) return;
	int mid = start + end >> 1;
	mergeSortRecursive(arr, start, mid);
	mergeSortRecursive(arr, mid + 1, end);

	int length = end - start + 1;
	int len1 = mid - start + 2;
	int len2 = end - mid + 1;
	int** left = (int**)malloc(sizeof(int*) * len1);
	int** right = (int**)malloc(sizeof(int*) * len2);

	int i,j ;
	for (i = 0, j = start; j <= mid; i++) left[i] = arr[j++];
	for (i = 0, j = mid + 1; j <= end; i++) right[i] = arr[j++];
	int MAXarray[2] = { INT_MAX, 0 };
	left[len1-1] = MAXarray;
	right[len2-1] = MAXarray;

	i = 0, j = 0;
	int index = 0;
	for (index = start; index <= end; index++)
	{
		if (left[i][0] < right[j][0]) arr[index] = left[i++];
		else arr[index] = right[j++];
	}
	free(left);
	free(right);
}

void mergeSort(int** arr, int arrSize)
{
	if (arrSize == 1) return;
	mergeSortRecursive(arr, 0, arrSize - 1);
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
	int** result = (int**)malloc(sizeof(int*) * intervalsSize);
	int resultSize = 0;
	mergeSort(intervals, intervalsSize);

	int overlapStart;
	bool isOverlapping = false;
	for (int i = 1; i < intervalsSize; i++)
	{
		if (isOverlapping)
		{
			// stop overlapping
			if (intervals[i-1][1] < intervals[i][0])
			{
				int* a = (int*)malloc(sizeof(int) * 2);
				a[0] = overlapStart;
				a[1] = intervals[i][1];
				result[resultSize++] = a;
			}
		}
		else
		{
			// start overlapping
			if (intervals[i][1] > intervals[i + 1][0]) overlapStart = intervals[i][0];
			else
			{
				int* a = (int*)malloc(sizeof(int) * 2);
				*a = *intervals[i];
				result[resultSize++] = a;
			}
		}
	}

	*returnSize = resultSize;
	return result;
}