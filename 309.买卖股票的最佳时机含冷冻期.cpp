/*
 * @Author: bingsfan mh.sun3@outlook.com
 * @Date: 2025-03-31 15:41:29
 * @LastEditors: bingsfan mh.sun3@outlook.com
 * @LastEditTime: 2025-03-31 16:31:34
 * @FilePath: \scatternd-channelastd:\vscode_code\leetcode\309.买卖股票的最佳时机含冷冻期.cpp
 * @Description:
 *
 */
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution
{
  public:
    /*
      定义一个冷冻期的状态，即为状态2，持有股票的状态只能从前一天是非冷冻期过来
      而今天如果是冷冻期，前一天肯定刚卖出去，前一天肯定是持有的
  */
 /*    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]); // 非冷冻期，之前就是非冷冻期，或者前一天是冷冻期
            dp[i][2] = dp[i - 1][0] + prices[i]; // 冷冻期，前一天刚卖出去
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    } */
    /*
     定义一个冷冻期的状态，即为状态2，持有股票的状态只能从前一天是非冷冻期过来
     而今天如果是冷冻期，前一天肯定刚卖出去，前一天肯定是持有的
     定义四个状态，一个是持有，一个是刚卖，一个是冷冻，一个是非冷冻
 */
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            // 持有的状态，要么之前就持有，要么前一天是非冷冻期,前一天是冷冻期也行
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i-1][2] - prices[i]));
            // 刚卖出去的状态,前一天肯定持有
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 冷冻期，前一天刚刚卖出去
            dp[i][2] = dp[i - 1][1];
            // 非冷冻期，可以自由活动了，前一天是冷冻期或者前一天本身就是非冷冻期
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]);
        }
        int res = max(dp.back()[3], max(dp.back()[2], dp.back()[1]));
        return res;
    }
};
// @lc code=end
