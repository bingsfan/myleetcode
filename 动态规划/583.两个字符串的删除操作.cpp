/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution
{
  public:
    int minDistance(string word1, string word2)
    {
        // 先求出最长公共子序列
        vector<vector<int>> dp(501, vector<int>(501, 0));
        int l = 0;
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        l = dp[word1.size()][word2.size()];
        return word1.size() + word2.size() - 2 * l;
    }
};
// @lc code=end
