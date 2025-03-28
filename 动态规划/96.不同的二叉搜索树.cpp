/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution
{
  public:
    /*
    这道题是我慢慢推出来的，左子树可能有0-i-1种方式，同理右子树也是这样
    dp[i]+=dp[j]*dp[i-j-1]
    dp[i]代表由i个节点组成的二叉搜索树有这么多种
    因为有累加，因此统一初始化成0,前两个初始化成1就行了
  */
    int numTrees(int n)
    {
        vector<int> dp(20, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end
