#pragma once
#include <iostream>
#include <unordered_map>

// runtime: 16ms, faster than 61.63% submissions
// memory : 8.3MB, less than 53.91% submissions

using namespace std;

class LongestSubstring {
public :
	int lengthOfLongestSubstring(string s) 
	{
		int result = 0;

		// key is the char, value is the count
		unordered_map<char, int> hash_table;
		int left = 0, right = 0;

		// start comparesion
		while (right < s.length())
		{
			// fix the left pointer, and move the right pointer to the right
			char right_char = s[right];
			hash_table[right_char]++;
			
			// if some character appear two times, then start moving left pointer
			// break if any frequency is less than 1
			while (hash_table[right_char] > 1 && left < s.size()) {
				char left_char = s[left];
				hash_table[left_char]--;
				left++;
			}

			result = max(result, right - left + 1);
			right++;
		}

		return result;
	}



	void CheckAnswer() 
	{
		string s = "abcabcbb";
		cout << lengthOfLongestSubstring(s);
	}
};