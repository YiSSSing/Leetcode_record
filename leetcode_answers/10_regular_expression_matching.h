#pragma once

#include <iostream>
#include <limits.h>

// runtime: 156ms, faster than 11.95% submissions
// memory : 13.4MB, less than 16.87% submissions


using namespace std;

class RegularExpressionMatching
{
public :
	bool isMatch(string s, string p) 
	{
		if (p.empty()) return s.empty();
		bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

		// if next one is star
		if (p.length() >= 2 && p[1] == '*') return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
		// if next one is char
		else return first_match && isMatch(s.substr(1), p.substr(1));
	}

	void CheckAnswer() 
	{
		if (isMatch("ab", ".*c")) cout << "yes" << endl;
		else cout << "no" << endl;
	}
};