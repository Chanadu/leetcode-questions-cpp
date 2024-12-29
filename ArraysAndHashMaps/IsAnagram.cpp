//
// Created by chanadu on 12/20/24.
//

#include <map>
#include <string>
#include <vector>

class Solution {
   public:
	bool isAnagram(std::string s, std::string t) {
		if (s.length() != t.length())
			return false;
		std::map<char, int> sm;
		std::map<char, int> tm;

		for (int i = 0; i < s.length(); i++) {
			sm[s[i]]++;
			tm[t[i]]++;
		}

		return sm == tm;
	}

	bool optimalSolution(std::string s, std::string t) {
		if (s.length() != t.length())
			return false;
		std::vector<int> count(26, 0);
		for (int i = 0; i < s.length(); i++) {
			count[s[i] - 'a']++;
			count[t[i] - 'a']--;
		}
		for (int c : count)
			if (c != 0)
				return false;

		return true;
	}
};
