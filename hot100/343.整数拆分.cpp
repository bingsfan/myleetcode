/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 1);
		for(int i = 3; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				dp[i] = max({ j * (i - j), j * dp[i - j], dp[i] });
			}
		}
		return dp[n];
	}
};
// @lc code=end

