#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		std::unordered_map<std::string, std::vector<std::string>> map;

		for (std::string s : strs) {
			std::vector<int> charMap(26, 0);
			for (char c : s) {
				charMap[c - 'a']++;
			}
			std::string keyString = std::string(charMap.begin(), charMap.end());
			map[keyString].push_back(s);
		}

		std::vector<std::vector<std::string>> returnVec;

		for (auto const& it : map) {
			returnVec.push_back(it.second);
		}
		return returnVec;
	}
};