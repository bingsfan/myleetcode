/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
	int countSubstrings(string s) {
		int n	= s.size();
		int res = n;
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		for(int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		for(int i = n - 1; i >= 0; i--) {
			for(int j = i + 1; j < n; j++) {
				if(j - i == 1 && s[i] == s[j]) {
					dp[i][j] = true;
				} else if(j - i > 1 && s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1];
				}
				if(dp[i][j])
					res++;
			}
		}
		return res;
	}
};
// @lc code=end

