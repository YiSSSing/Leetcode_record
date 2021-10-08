#pragma once

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0) return 0;
    int i = 0, n = 1;
    for (i = 1; i < numsSize; i++)
        if (nums[i] != nums[i - 1]) nums[n++] = nums[i];
    return n;
}