#pragma once

#include <iostream>
#include <limits.h>
#include <vector>

// runtime: 184ms, faster than 5.77% submissions
// memory : 58.9MB, less than 79.31% submissions


using namespace std;

class ContainerWithMostWater 
{
public :
	int maxArea(vector<int>& height) 
	{
		int left = 0, right = height.size() - 1;
		int area_tem = 0, area = 0, length = height.size()-1;
		// Check from two sides to center
		while ( left != right )
		{
			if ( height[left] > height[right] ) 
			{
				area_tem = height[right] * length;
				area = area_tem > area ? area_tem : area;
				right--;
			}
			else 
			{
				area_tem = height[left] * length;
				area = area_tem > area ? area_tem : area;
				left++;
			}
			length--;
		}
		return area;
	}

	void CheckAnswer()
	{
		vector<int> v = {1,8,6,2,5,4,8,3,7};
		cout << maxArea(v) << endl;
	}
};