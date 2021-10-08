#pragma once
#include <iostream>
#include <vector>

// runtime: 32ms, faster than 59.58% submissions
// memory : 90.3MB, less than 7.1% submissions

using namespace std;

class MedianOfTwoSortedArray {
public :
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int i = 0, j = 0;
		vector<int> result;

		// Combine two sorted array
		while ( i < nums1.size() && j < nums2.size() )
		{
			if (nums2[j] >= nums1[i])
			{
				result.push_back(nums1[i]);
				i++;
			}
			else 
			{
				result.push_back(nums2[j]);
				j++;
			}
		}

		// if nums2 is longer than nums1, then append all elements on result array
		if (i == nums1.size())
			for (j; j < nums2.size(); j++) result.push_back(nums2[j]);
		else
			for (i; i < nums1.size(); i++) result.push_back(nums1[i]);
		i = i + j;

		// Calculate the median
		if (i % 2 == 1) return result[i / 2];
		else return (double)(result[i / 2] + result[(i/ 2)-1]) / 2;
	}

	void CheckAnswer()
	{
		vector<int> v1 = { 1,3 };
		vector<int> v2 = { 2 };
		vector<int> v3 = { 1,2 };
		vector<int> v4 = { 3,4 };

		cout << findMedianSortedArrays(v1, v2) << endl;
		cout << findMedianSortedArrays(v3, v4) << endl;
	}
};