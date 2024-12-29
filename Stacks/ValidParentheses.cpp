#include <stack>
#include <string>
#include <unordered_map>

class Solution {
   public:
	bool isValid(std::string s) {
		std::stack<char> st;

		for (char c : s) {
			switch (c) {
				case '(':
				case '{':
				case '[':
					st.push(c);
					break;

				case ')':
					if (st.empty() || st.top() != '(')
						return false;
					st.pop();
					break;
				case ']':
					if (st.empty() || st.top() != '[')
						return false;
					st.pop();
					break;
				case '}':
					if (st.empty() || st.top() != '{')
						return false;
					st.pop();
					break;
			}
		}

		return st.empty();
	}

	bool withMap(std::string s) {
		std::stack<char> stack;
		std::unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};

		for (char c : s) {
			if (map.count(c) == 0) {
				stack.push(c);
				continue;
			}

			if (stack.empty() || map[c] != stack.top()) {
				return false;
			}
			stack.pop();
		}

		return stack.empty();
	}
};