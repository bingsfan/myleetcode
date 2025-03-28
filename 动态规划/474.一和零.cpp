/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution
{
  public:
  /* 
    这里字符串数组strs里面的每一个字符串就是一个物品，背包有两个容量一个装0一个装1
    dp[i][j]代表了0的最大容量为i，1的最大容量为j的背包最大能装多少个物品
    dp[i][j] =  max(dp[i][j],1+dp[i-num0][j-num1])
    背包容量需要从后向前遍历
  */
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(101, vector<int>(101, 0));
        for (string str : strs)
        {
            int num1 = 0, num0 = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    num0++;
                }
                else
                {
                    num1++;
                }
            }
            for (int i = m; i >= num0; i--)
            {
                for (int j = n; j >= num1; j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - num0][j - num1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
