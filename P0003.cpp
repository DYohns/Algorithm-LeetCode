/*
ID: 3
Desc: ���һ���ַ����в��ظ��ַ����������ַ�������󳤶ȣ����磺
	Input: "abcabcbb"
	Output: 3
	PS: "abcabcbb" ������������ظ��ַ������ַ�����"abc"
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