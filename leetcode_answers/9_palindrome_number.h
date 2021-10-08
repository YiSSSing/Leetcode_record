#pragma once


#include <iostream>
#include <limits.h>

// runtime: 20ms, faster than 23.12% submissions
// memory : 6MB, less than 28.14% submissions


using namespace std;

class PalindromeNumber 
{
public :
	bool isPalindrome(int x)
	{
		if (x == 0) return true;
		if (x < 0 || x % 10 == 0) return false;

		int pop_out = 0;
		// Spilt the integer by the center
		// for example, 123456 = 123 and 654, 123321 = 123 and 123
		while (x > pop_out) 
		{
			pop_out = pop_out * 10 + x % 10;
			x /= 10;
		}

		return x == pop_out || x == pop_out / 10;
	}
};