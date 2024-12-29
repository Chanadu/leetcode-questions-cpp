#include <unordered_map>
#include <vector>

class Solution {
   public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			if (map.count(target - num) != 0) {
				return std::vector{map[target - num], i};
			}
			map[num] = i;
		}
		return std::vector{-1, -1};
	}
};