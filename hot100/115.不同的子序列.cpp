/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
	int numDistinct(string s, string t) {
		// 要计算s中t出现的次数
		int n1 = s.size(), n2 = t.size();
		vector<vector<uint64_t>> dp(n1 + 1, vector<uint64_t>(n2 + 1, 0));
		for(int i = 0; i <= n1; i++) {
			dp[i][0] = 1;
		}
		for(int i = 1; i <= n1; i++) {
			for(int j = 1; j <= n2; j++) {
				if(s[i - 1] == t[j - 1]) {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[n1][n2];
	}
};
// @lc code=end

