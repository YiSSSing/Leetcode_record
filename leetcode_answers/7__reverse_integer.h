#pragma once


#include <iostream>
#include <limits.h>

// runtime: 4ms, faster than 42.85% submissions
// memory : 6MB, less than 29.76% submissions


using namespace std;

class ReverseInteger
{
public :
	int reverse(int x) 
	{
		int result = 0, pop_from_right = 0;
		while ( x != 0 ) 
		{
			pop_from_right = x % 10;
			x /= 10;

			// Detect for overflow
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop_from_right > 7)) return 0;
			if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop_from_right < -8)) return 0;

			result = result * 10 + pop_from_right;
		}
		return result;
	}

	void CheckAnswer() 
	{
		int x = 1534236469;
		cout << reverse(x) << endl;
	}
};