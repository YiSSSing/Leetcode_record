#pragma once


#include <iostream>
#include <vector>

// runtime: 24ms, faster than 32.04% submissions
// memory : 16.8MB, less than 16.44% submissions


using namespace std;

class ZigZag
{
public :
	string convert(string s, int numRows)
	{
		if (s.length() <= 2 || numRows == 1) return s;
		string result = s;
		int shift = -1, row = 0;

		vector< vector<char> > chars;
		for (int i = 0; i < numRows; i++) 
		{
			vector<char> row;
			chars.push_back(row);
		}

		// Devide the string into numRows vectors
		for (int i = 0; i < s.length(); i++) 
		{
			chars[row].push_back(s[i]);
			if (row == numRows - 1 || row == 0) shift *= (-1);
			row += shift;
		}

		// Combine the substring
		shift = 0;
		for (row = 0; row < numRows; row++)
		{
			for ( int i = 0; i < chars[row].size(); i++) 
			{
				result[shift] = chars[row][i];
				shift++;
			}
		}
		
		return result;
	}

	void CheckAnswer()
	{
		string s = "ABC";
		// output = "PINALSIGYAHRPI"
		cout << convert(s, 1) << endl;
	}
};