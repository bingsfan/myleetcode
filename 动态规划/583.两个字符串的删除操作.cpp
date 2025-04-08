/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution
{
  public:
    /*
    方法一：
        找到两个字符串的最长公共子序列的长度为lcs，用n1+n2-2*lcs就可以了
        方法一更容易理解一点
    方法二：
        定义dp[i][j]是word1的子序列和word1的子序列相等需要删除的个数
        如果相等，直接继承前一步的状态，如果不相等，需要删除，+1这个部分体现出了删除的元素个数
        if(word[i-1]==word[j-1])
            dp[i][j]=dp[i-1][j-1];
        else
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1
        因为这有min所以得初始化一个大的值,长度最大也就是500了
        然后dp[i][0]=i;dp[0][j]=j;
        返回值还是dp[n1][n2]
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
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
    int minDistance1(string word1, string word2)
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
