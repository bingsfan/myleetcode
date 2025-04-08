/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
  public:
    /*
    392题是判断s是否是t的子序列，这个题是要求t是否是s的子序列 + s有多少子序列可以是t
    以i-1结尾的子序列，但是也可以不要s[i-1]，但是以i-1为结尾的子数组必须要
    定义dp[i][j],t的以j-1为结尾的子序列在s以i-1为结尾的子序列出现了dp[i][j]次
    初始化：如果i=0，那肯定所有都等0
            如果j=0，dp[i][0]=1
    返回值？就是dp[n1][n2]
*/
    int numDistinct(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<uint64_t>> dp(n1 + 1, vector<uint64_t>(n2 + 1, 0));
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end
