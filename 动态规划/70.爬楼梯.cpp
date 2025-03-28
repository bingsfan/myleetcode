/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
  public:
    /*
    可以从两种状态到达第i阶，一种是从i-1迈一步，一种从i-2迈两步
    定义dp[i]为到达第i阶楼梯的方法数，则可以写出递推公式
    初始化：dp[0]?   dp[1]肯定等于1，但是dp[2]=2,因此dp[0]=1
  */
    int climbStairs(int n)
    {
        vector<int> dp(46, 1);
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end
