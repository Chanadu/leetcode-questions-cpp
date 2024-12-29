#include <iostream>
#include <stack>
#include <string>
#include <vector>
class Solution {
   public:
	int evalRPN(std::vector<std::string>& tokens) {
		std::stack<int> stack;
		for (std::string token : tokens) {
			char c = token[0];
			switch (c) {
				case '+': {
					int val1 = stack.top();
					stack.pop();
					int val2 = stack.top();
					stack.pop();

					stack.push(val2 + val1);
					break;
				}
				case '-': {
					int val1 = stack.top();
					stack.pop();
					int val2 = stack.top();
					stack.pop();

					stack.push(val2 - val1);
					break;
				}
				case '*': {
					int val1 = stack.top();
					stack.pop();
					int val2 = stack.top();
					stack.pop();

					stack.push(val2 * val1);
					break;
				}
				case '/': {
					int val1 = stack.top();
					stack.pop();
					int val2 = stack.top();
					stack.pop();

					stack.push(val2 / val1);
					break;
				}
				default:
					stack.push(c - '0');
			}
		}

		return stack.top();
	}
	int evalRPN2(std::vector<std::string>& tokens) {
		std::stack<int> stack;
		for (std::string token : tokens) {
			if (token == "+") {
				int val1 = stack.top();
				stack.pop();
				int val2 = stack.top();
				stack.pop();

				stack.push(val2 + val1);
				break;
			}
			else if (token == "-") {
				int val1 = stack.top();
				stack.pop();
				int val2 = stack.top();
				stack.pop();

				stack.push(val2 - val1);
				break;
			}
			else if (token == "*") {
				int val1 = stack.top();
				stack.pop();
				int val2 = stack.top();
				stack.pop();

				stack.push(val2 * val1);
				break;
			}
			else if (token == "/") {
				int val1 = stack.top();
				stack.pop();
				int val2 = stack.top();
				stack.pop();

				stack.push(val2 / val1);
				break;
			} else
				stack.push(std::stoi(token));
		}
		return stack.top();
	}
};

int main() {
	Solution s;
	std::vector<std::string> v{"1", "2", "+", "3", "*", "4", "-"};
	int val = s.evalRPN(v);

	std::cout << "final " << val << "\n";
}