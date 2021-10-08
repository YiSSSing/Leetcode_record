#pragma once

int searchInsert(int* nums, int numsSize, int target)
{
	// need O(logn) -> binary search
	int left = 0, right = numsSize - 1;
	if (right == 0)
	{
		if (target <= nums[0]) return 0;
		else return 1;
	}

	int m;
	while (left < right)
	{
		m = (left + right) >> 1;
		if (target == nums[m]) return m;
		else if (target > nums[m]) left = m + 1;
		else right = m - 1;
	}

	if (target <= nums[left]) return left;
	else return left + 1;
}