#include <queue>
#include <stack>
#include <utility>
#include <vector>

class Solution {
   public:
	std::vector<int> bruteforce(std::vector<int>& temperatures) {
		std::vector<int> v(temperatures.size(), 0);

		for (int i = 0; i < temperatures.size(); i++) {
			for (int j = i + 1; j < temperatures.size(); j++) {
				if (temperatures[i] < temperatures[j]) {
					v[i] = j - i;
					break;
				}
			}
		}
		return v;
	}

	std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
		std::vector<int> v(temperatures.size(), 0);
		// Temp, Idx
		std::stack<std::pair<int, int>> stack;

		for (int i = 0; i < temperatures.size() - 1; i++) {
			int temp = temperatures[i];

			while (!stack.empty()) {
				if (stack.top().first < temp) {
					v[stack.top().second] = i - stack.top().second;
					stack.pop();
				} else {
					break;
				}
			}
			stack.push({temp, i});
		}

		return v;
	}
};