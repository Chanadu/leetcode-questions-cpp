#include <cctype>
#include <string>
#include <vector>

class Solution {
   public:
	std::string encode(std::vector<std::string>& strs) {
		std::string finalStr;

		for (std::string s : strs) {
			int len = s.length();
			std::string newStr = s;
			newStr = std::to_string(len) + ":" + newStr;
			finalStr += newStr;
		}
		return finalStr;
	}

	std::vector<std::string> decode(std::string s) {
		std::vector<std::string> v;

		for (int i = 0; i < s.length();) {
			int j = i;
			while (s[j] != ':') {
				j++;
			}
			int numLen = j - i;
			int len = std::atoi(s.substr(i, numLen).c_str());

			i = j + 1;
			std::string currentString = s.substr(i, len - 1);
			v.push_back(currentString);

			i += len ;
		}
		return v;
	}

	// 2:AB3:CDE1:F
};