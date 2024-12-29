#include <unordered_map>
#include <vector>
class Solution {
   public:
	int longestConsecutiveStupid(std::vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int min, max;
		min = max = nums[0];

		for (int num : nums) {
			if (num < min) {
				min = num;
			}
			if (num > max) {
				max = num;
			}
		}

		std::vector<bool> bucket(max - min + 1, false);
		for (int num : nums) {
			bucket[num - min] = true;
		}

		int maxCount = 0;
		int currentCount = 0;
		for (int i = 0; i < bucket.size(); i++) {
			if (!bucket[i]) {
				currentCount = 0;
				continue;
			}

			currentCount++;
			if (maxCount < currentCount) {
				maxCount = currentCount;
			}
		}

		return maxCount;
	}

	int actuallyusedthehbrain(std::vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int min, max;
		min = max = nums[0];

		for (int num : nums) {
			if (num < min) {
				min = num;
			}
			if (num > max) {
				max = num;
			}
		}

		std::unordered_map<int, bool> map;
		for (int num : nums) {
			map[num] = false;
		}

		int maxCount = 0;
		for (auto& pair : map) {
			if (pair.second) {
				continue;
			}
			map[pair.first] = true;

			int currentCount = 0;
			int currentVal = pair.first;
			while (map.count(currentVal) != 0) {
				currentCount++;
				currentVal++;
			}
			if (maxCount < currentCount) {
				maxCount = currentCount;
			}
		}

		return maxCount;
	}
};