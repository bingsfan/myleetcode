/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
  public:
    int numDistinct(string s, string t)
    {
        vector<vector<uint64_t>> dp(1001, vector<uint64_t>(1001, 0));
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end
