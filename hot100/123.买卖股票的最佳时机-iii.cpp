/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(4, 0));
		dp[0] = { -prices[0], 0, -prices[0], 0 };
		for(int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], 0 - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
		}
		return dp[n - 1][3];
	}
};
// @lc code=end

