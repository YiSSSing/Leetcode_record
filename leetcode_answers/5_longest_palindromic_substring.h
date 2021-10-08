#pragma once

#include <iostream>

// runtime: 168ms, faster than 47.84% submissions
// memory : 231.5MB, less than 23.09% submissions


using namespace std;

class LongestPalindromicSubstring {
public :
	string longestPalindrome(string s)
	{
		if ( s.length() < 1) return "";
		if (s.length() == 1) return s;

		int left = 0, length = 0;
		int len_odd = -1, len_even = -1;
		int radius = 0;
		for (int i = 0; i < s.length(); i++)
		{
			// Find the radius when center is at i and (i,i+1)
			len_odd = findRadius(s, i, i);
			len_even = findRadius(s, i, i + 1);

			// if center at i have longer palindromic and longer than the answer before
			if ( len_odd > len_even ) 
			{
				if (len_odd > length) 
				{
					radius = (len_odd - 1) / 2;
					left = i - radius;
					length = len_odd;
				}
			}
			// if center at (i,i+1) have longer palindromic and longer than the answer before
			else 
			{
				if (len_even > length)
				{
					radius = (len_even - 2) / 2;
					left = i - radius;
					length = len_even;
				}
			}
		}
		
		return s.substr(left, length);
	}

	/*
	*  Find the radius of the palindrome at center 
	*  left+1 (when result is odd) or left+1 & left+2 (when result is even)
	*/
	int findRadius(string s, int left, int right)
	{
		int i = left, j = right;
		while ( i > 0 && j < s.length() && s[i] == s[j]) 
		{
			i--;
			j++;
		}
		if (s[i] != s[j])
		{
			i++;
			j--;
		}
		return j - i + 1;
	}

	void CheckAnswer()
	{
		string s = "babad";
		cout << longestPalindrome(s) << endl;
	}
};