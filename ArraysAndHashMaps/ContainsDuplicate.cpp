//
// Created by chanadu on 12/19/24.
//
#include <unordered_set>
#include <vector>

class Solution {
   public:
	bool hasDuplicate(std::vector<int>& nums) {
		std::unordered_set<int> set;

		for (int num : nums) {
			if (auto iter = set.find(num); iter != set.end()) {
				return true;
			}
			set.insert(num);
		}
		return false;
	}

	bool solution(std::vector<int>& nums) {
		std::unordered_set<int> set{};

		for (int num : nums) {
			if (set.count(num) != 0) {
				return true;
			}
			set.insert(num);
		}
		return false;
	}
};
