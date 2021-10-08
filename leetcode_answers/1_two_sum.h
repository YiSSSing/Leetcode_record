
// Only complie once, include many time will only count at once
// equal to #ifndef and #endif, but is for the whole files
#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

// runtime: 4ms, faster than 98.93% submissions
// memory : 10.6MB, less than 52.16% submissions

using namespace std;

class TwoSum {
public :
	vector<int> twoSum(vector<int>& nums, int target) {
		// Build a hash table for searching
		unordered_map<int, int> hash_table;

		// Search for answer.
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			int left = target - nums[i];

			// If left can be found in hash map, return answer
			if (hash_table.find(left) != hash_table.end()) {
				result.push_back(hash_table[left]);
				result.push_back(i);
				return result;
			}

			// If cannot find left, put it into hash table.
			hash_table[nums[i]] = i;
		}

		// No answer, return null
		return result;
	}

	void CheckAnswer() {
		vector<int> example = {3,2,4};
		vector<int> result = this->twoSum(example, 6);
		cout << "[" << result[0] << "," << result[1] << "]";
	}

};