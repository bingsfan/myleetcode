/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(4, 0));
		dp[0][0] = -prices[0];
		for(int i = 1; i < n; i++) {
			dp[i][0] =
			 max({ dp[i - 1][0], dp[i - 1][2] - prices[i], dp[i - 1][3] - prices[i] });
			dp[i][1] = dp[i - 1][0] + prices[i];
			dp[i][2] = dp[i - 1][1];
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]);
		}
		return max({ dp.back()[1], dp.back()[2], dp.back()[3] });
	}
};
// @lc code=end

