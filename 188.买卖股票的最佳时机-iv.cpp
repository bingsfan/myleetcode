/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
  public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        // 新加入一个状态为空状态，之后奇数状态为持有，偶数为不持有，然后初始化
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = 1; j <= 2 * k; j += 2)
            {
                dp[i][j] = -prices[i];
            }
        }
        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 1; j <= 2 * k; j += 2)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};
// @lc code=end
