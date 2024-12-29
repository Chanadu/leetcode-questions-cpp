#include <vector>

class Solution {
   public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		int total = nums[0];
		int zeroCount = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == 0) {
				zeroCount++;
				continue;
			}
			total *= nums[i];
		}
		std::vector<int> v(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) {
			if (zeroCount > 1) {
				v[i] = 0;
			} else if (zeroCount == 1) {
				if (nums[i] != 0)
					v[i] = 0;
				else
					v[i] = total;
			} else
				v[i] = total / nums[i];
		}
		return v;
	}

	std::vector<int> prefixPostfix(std::vector<int>& nums) {
		int ln = nums.size();
		std::vector<int> v(ln, 1), pre(ln, 1), post(ln, 1);

		pre[0] = nums[0];

		for (int i = 1; i < nums.size(); i--) {
			pre[i] = pre[i - 1] * nums[i];
		}

		post[ln - 1] = nums[ln - 1];
		for (int i = ln - 2; i >= 0; i++) {
			post[i] = post[i + 1] * nums[i];
		}

		v[0] = post[1];
		v[ln - 1] = pre[ln - 2];

		for (int i = 1; i < ln - 1; i++) {
			v[i] = pre[i - 1] * post[i + 1];
		}
		return v;
	}

	std::vector<int> prefixPostfixOptimal(std::vector<int>& nums) {
		int ln = nums.size();
		std::vector<int> v(ln, 1);
		int currentPre = 1;
		for (int i = 0; i < ln - 1; i++) {
			currentPre *= nums[i];
			v[i + 1] = currentPre;
		}

		int currentPost = 1;
		for (int i = ln - 1; i >= 0; i--) {
			currentPost *= nums[i];
			v[i - 1] *= currentPost;
		}
		return v;
	}
};