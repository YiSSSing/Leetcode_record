#pragma once


int search(int* nums, int numsSize, int target)
{
	// need O(logn) -> binary search
	int left = 0, right = numsSize - 1;
	int m;

	while (left <= right)
	{
		m = (left + right) >> 1;
		if (nums[m] == target) return m;

		// nums[m] > nums[right] means the array is rotated
		if (nums[m] > nums[right])
		{
			if (target < nums[m] && target >= nums[left]) right = m - 1;
			else left = m + 1;
		}
		else
		{
			if (target > nums[m] && target <= nums[right] ) left = m + 1;
			else right = m - 1;
		}
	}
	return -1;
}