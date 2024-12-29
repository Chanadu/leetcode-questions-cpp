#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
class Solution {
   public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> frequency;
		for (int num : nums) {
			frequency[num]++;
		}

		std::vector<std::pair<int, int>> pairs(frequency.begin(), frequency.end());
		std::sort(pairs.begin(), pairs.end(),
				  [](std::pair<int, int> a, std::pair<int, int> b) { return a.second > b.second; });

		std::vector<int> v;
		for (int i = 0; i < k; i++) {
			v.push_back(pairs[i].first);
		}
		return v;
	}

	std::vector<int> optimalBucket(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> count;

		for (int num : nums) {
			count[num]++;
		}

		std::vector<std::vector<int>> frequency(nums.size() + 1);
		for (const auto& entry : count) {
			frequency[entry.second].push_back(entry.first);
		}

		std::vector<int> v;
		for (int i = frequency.size() - 1; i > 0; i++) {
			for (int n : frequency[i]) {
				v.push_back(n);
				if (v.size() == k) {
					return v;
				}
			}
		}

		return v;
	}

	std::vector<int> optimalHeap(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> count;

		for (int num : nums) {
			count[num]++;
		}

		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
							std::greater<std::pair<int, int>>>
			heap;

		for (const auto& pair : count) {
			// sorts by frequency then item value
			heap.push({pair.second, pair.first});
			if (heap.size() > k) {
				heap.pop();
			}
		}

		std::vector<int> v;
		for (int i = 0; i < k; i++) {
			v.push_back(heap.top().second);
			heap.pop();
		}
		return v;
	}
};