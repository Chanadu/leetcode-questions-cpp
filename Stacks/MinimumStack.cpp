#include <algorithm>
#include <climits>
#include <queue>
#include <stack>

class MinStack {
	std::stack<int> stack;

   public:
	MinStack() {}

	void push(int val) { stack.push(val); }

	void pop() { stack.pop(); }

	int top() { return stack.top(); }

	int getMin() {
		std::stack<int> newStack;
		int min = INT_MAX;
		while (!stack.empty()) {
			newStack.push(stack.top());
			min = std::min(min, stack.top());
			stack.pop();
		}

		while (!newStack.empty()) {
			stack.push(newStack.top());
			newStack.pop();
		}

		return min;
	}
};

class MinStack2 {
	std::stack<int> stack;
	std::stack<int> minStack;

   public:
	MinStack2() {}

	void push(int val) {
		if (stack.empty()) {
			minStack.push(val);
		} else {
			minStack.push(std::min(minStack.top(), val));
		}
		stack.push(val);
	}

	void pop() { 
		stack.pop();
		minStack.pop();
	}

	int top() { return stack.top(); }

	int getMin() { return minStack.top(); }
};