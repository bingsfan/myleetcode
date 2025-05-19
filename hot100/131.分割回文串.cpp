/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
	bool isHuiwen(string &s, int l, int r) {
		if(l == r) {
			return true;
		}
		int i = l, j = r;
		while(i <= j) {
			if(s[i] != s[j]) {
				return false;
			}
			i++, j--;
		}
		return true;
	}
	vector<string> path2;
	vector<vector<string>> res2;
	void traceback131(string &s, int startIndex) {
		if(startIndex == s.size()) {
			res2.push_back(path2);
			return;
		}
		for(int i = startIndex; i < s.size(); i++) {
			if(isHuiwen(s, startIndex, i)) {
				string parts = s.substr(startIndex, i - startIndex + 1);
				path2.push_back(parts);
				traceback131(s, i + 1);
				path2.pop_back();
			} else {
				continue;
			}
		}
	}
	vector<vector<string>> partition(string s) {
		traceback131(s, 0);
		return res2;
	}
};
// @lc code=end

