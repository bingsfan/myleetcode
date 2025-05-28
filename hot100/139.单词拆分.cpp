/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
	bool wordBreak(string s, vector<string> &wordDict) {
		s.insert(s.begin(), ' ');
		int bagsize = s.size();
		vector<bool> dp(bagsize + 2, false);
		dp[0] = true;
		unordered_set<string> uset(wordDict.begin(), wordDict.end());
		for(int i = 1; i < bagsize; i++) {
			for(int j = 1; j <= i; j++) {
				string tmp = s.substr(j, i - j + 1);
				if(dp[j - 1] == true && uset.count(tmp)) {
					dp[i] = true;
				}
			}
		}
		return dp[bagsize - 1];
	}
};
// @lc code=end

