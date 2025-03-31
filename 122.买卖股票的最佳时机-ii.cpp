/*
 * @Author: bingsfan mh.sun3@outlook.com
 * @Date: 2025-03-31 14:35:35
 * @LastEditors: bingsfan mh.sun3@outlook.com
 * @LastEditTime: 2025-03-31 14:45:17
 * @FilePath: \scatternd-channelastd:\vscode_code\leetcode\122.买卖股票的最佳时机-ii.cpp
 * @Description: 
 * 
 */
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
  public:
    /*
  dp数组定义：第i天的收益情况，理论上这题没有购买次数的限制
    每一天只有两个状态，持有或者不持有,肯定不持有的钱比持有的多
    这个题可以买卖多次，因此今天刚持有的钱不一定是-prices[i]，应该是前一天没有，今天刚有dp[i - 1][1] - prices[i]
    第i天持有可能是之前就持有了，也可能是今天刚持有，定义状态0
    第i天不持有可能是之前就没有了，也可能是今天刚不持有，定义状态1
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  */
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0], dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};
// @lc code=end
