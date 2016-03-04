/*
ID: 3
Desc: 求出一段字符串中不重复字符的连续子字符串的最大长度，例如：
	Input: "abcabcbb"
	Output: 3
	PS: "abcabcbb" 中最长的连续不重复字符的子字符串是"abc"
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
int dp[99999];
string subString;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		dp[0] = 1;
		size_t found;
		subString = s.substr(0, 1);
		for (int i = 1; i < s.length(); i++) {
			found = subString.find(s[i]);
			subString += s[i];
			if (found != string::npos) {
				subString = subString.substr(found + 1);
			}
			if (subString.length() > dp[i - 1]) {
				dp[i] = subString.length();
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
		return dp[s.length() - 1];
	}
};