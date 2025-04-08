/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution
{
  public:
    /*
    输入：word1 = "horse", word2 = "ros" 输出3
    将word1转换成word2所需要的最小次数，可以进行删除，插入和替换
    定义dp[i][j],为word1的子序列[0,i-1]变成word2的子序列所需要的最少步骤，和删除那个很像
    如果相等， 那就不用管，直接继承之前的状态
    否则要删除或者替换，删除word2等于插入word1,替换的话肯定就想等了，直接继承之前的状态
*/
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 501));
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end
