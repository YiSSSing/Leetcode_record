#pragma once


#include <iostream>
#include <limits.h>

// runtime: 0ms, faster than 100% submissions
// memory : 7MB, less than 82.09% submissions


using namespace std;

class StringToInteger 
{
public :
	int myAtoi(string s ) 
	{
		int index = 0, _codeOfChar = (int)s[0], result = 0, sign = 1;

		// If the leading is not sign or numbers.
		if (!(_codeOfChar >= 48 || _codeOfChar <= 57 || _codeOfChar != 45 || _codeOfChar != 43)) return 0;

		// Detect for spaces.
		while ( index < s.length() ) 
		{
			_codeOfChar = (int)s[index];

			// if the leading is space
			if (_codeOfChar == 32 ) index++;
			// if the leading is sign
			else if (_codeOfChar == 45 || _codeOfChar == 43)
			{
				if ((int)s[index + 1] < 48 || (int)s[index + 1] > 57) return 0;
				index++;
				sign = (_codeOfChar == 45 ? -1 : 1);
			}
			else break;
		}

		int number = 0, shift = 10;
		while ( index < s.length() ) 
		{
			_codeOfChar = (int)s[index] - 48;
			if (_codeOfChar >= 0 && _codeOfChar <= 9)
			{
				_codeOfChar *= sign;
				// Detect for overflow
				if (result > INT_MAX / 10 || (result == INT_MAX / 10 && _codeOfChar > 7)) return INT_MAX;
				if (result < INT_MIN / 10 || (result == INT_MIN / 10 && _codeOfChar < -8)) return INT_MIN;

				result = result * shift + _codeOfChar;
			}
			else break;
			index++;
		}

		return result;
	}

	void CheckAnswer()
	{
		string a = "42";
		string b = "    -42";
		string c = "4193 with words";
		string d = "words and 987";
		string e = "-91283472332";
		//cout << myAtoi(a) << endl;
		//cout << myAtoi(b) << endl;
		//cout << myAtoi(c) << endl;
		//cout << myAtoi(d) << endl;
		cout << myAtoi(e) << endl;
	}

	void printASCIIcodeToChar()
	{
		// space = 32
		// 43 = +, 45 = -, 48= 0, 57 = 9
		for (int i = 32; i <= 126; i++) 
		{
			cout << "ASCII " << i << " is " << (char)i << endl;
		}
	}
};