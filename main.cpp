#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
    bool isAnagram(std::string s, std::string t) {
		if (s.length() != t.length()) return false;
		std::map<char, int> sm;
		std::map<char, int> tm;

		for (int i = 0; i < s.length(); i++) {
			sm[s[i]]++;
			tm[t[i]]++;
		}

		return sm == tm;
    }
