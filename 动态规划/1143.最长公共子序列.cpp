/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution
{
  public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(1001, vector<int>(1001, 0));
        int res = 0;
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] > res)
                {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end
