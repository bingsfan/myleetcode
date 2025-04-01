/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
  public:
  /* 
    我是定义了一个bool类型的dp数组，不过需要处理一下特殊的条件好像是，测试用例里面光处理s为空就行了
    也可以采用跟最长公共子序列差不多的解法，算出来这两个最长公共子序列的长度，看看和s的长度相等不
  */
    /* bool isSubsequence(string s, string t)
    {
        vector<vector<bool>> dp(101, vector<bool>(10001, false));
        if (s.empty())
        {
            return true;
        }
        for (int j = 0; j < t.size(); j++)
        {
            dp[0][j] = true;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[s.size()][t.size()];
    } */
    bool isSubsequence(string s, string t)
    {
        vector<vector<int>> dp(101, vector<int>(10001, 0));
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};
// @lc code=end
