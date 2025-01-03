#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
	void back(std::vector<std::string>& v, int n, std::string current, int open, int closed) {
		if (current.length() == n * 2) {
			v.push_back(current);
			return;
		}

		if (closed < open) {
			back(v, n, current + ")", open, closed + 1);
		}
		if (open < n) {
			back(v, n, current + "(", open + 1, closed);
		}
	}

	std::vector<std::string> generateParenthesis(int n) {
		if (n == 1) {
			return {"()"};
		}
		std::vector<std::string> v;
		back(v, n, "", 0, 0);
		return v;
	}
};