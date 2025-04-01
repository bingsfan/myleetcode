/*
 * @Author: bingsfan mh.sun3@outlook.com
 * @Date: 2025-03-31 13:50:33
 * @LastEditors: bingsfan mh.sun3@outlook.com
 * @LastEditTime: 2025-03-31 14:20:27
 * @FilePath: \scatternd-channelastd:\vscode_code\leetcode\121.买卖股票的最佳时机.cpp
 * @Description: 
 * 
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
  public:
    /*
    每一天只有两个状态，持有或者不持有,肯定不持有的钱比持有的多
    第i天持有可能是之前就持有了，也可能是今天刚持有，定义状态0
    第i天不持有可能是之前就没有了，也可能是今天刚不持有，定义状态1
  */
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0], dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int t1 = dp[i - 1][0];
            int t2 = -prices[i];
            dp[i][0] = max(t1, t2);
            int r1 = dp[i - 1][1];
            int r2 = dp[i - 1][0] + prices[i];
            dp[i][1] = max(r1, r2);
        }
        return dp[prices.size() - 1][1];
    }
};
// @lc code=end
