/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
  public:
    /*
    一个数i可以拆分成j 和 i-j
    定义dp[i]为i拆分成k个正整数的和后的整数乘积的最大值
    dp[i] = j*(i-j) 或者j*dp[i-j],一个是拆分成固定的两个数，一个拆分成多个
    初始化dp[2]=1
  */
    int integerBreak(int n)
    {
        vector<int> dp(60, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end
