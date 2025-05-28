/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
	bool isSubsequence(string s, string t) {
		// 判断s是否是t的子序列,用公共子序列的模板来做，看看公共子序列的长度是否和s一样
		int n1 = s.size(), n2 = t.size();
		int res = 0;
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
		for(int i = 1; i <= n1; i++) {
			for(int j = 1; j <= n2; j++) {
				if(s[i - 1] == t[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				res = max(res, dp[i][j]);
			}
		}
		return res == s.size();
	}
};
// @lc code=end

