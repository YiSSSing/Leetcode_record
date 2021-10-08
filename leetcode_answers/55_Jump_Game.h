#pragma once




bool canJump(int* nums, int numsSize) 
{
	if (numsSize == 0 ) return false;

	int max = 0, step = 1;
	for (int i = 0; i < numsSize; i++)
	{
		step--;
		if (i + nums[i] > max)
		{
			max = i + nums[i];
			step = nums[i];
		}
		if (step == 0 && i < numsSize - 1) return false;
	}
	return true;
}