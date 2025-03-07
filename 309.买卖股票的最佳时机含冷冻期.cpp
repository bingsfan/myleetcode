/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 定义三个状态
        // dp[i][0] 表示第 i 天持有股票的最大收益
        // dp[i][1] 表示第 i 天不持有股票且处于冷冻期的最大收益
        // dp[i][2] 表示第 i 天不持有股票且不处于冷冻期的最大收益
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            // 第 i 天持有股票的最大收益,不持有股票且不在冷冻期才能在第 i 天买入股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 第 i 天不持有股票且处于冷冻期的最大收益，
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 第 i 天不持有股票且不处于冷冻期的最大收益
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[n-1][2],dp[n-1][1]);
    }
};
// @lc code=end

