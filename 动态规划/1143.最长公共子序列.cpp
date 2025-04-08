/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution
{
  public:
    /*
    要求两个字符串的最长公共子序列的长度，最长公共子数组很像
    定义dp[i][j]：text1以i-1为结尾的子序列和text2以j-1为结尾的子序列，这两个公共子序列的长度
    要求的其实是dp[i][j]的最大值，初始化统一为0
    if(text1[i-1]==text[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
    }else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    这个else里面是因为如果不相等，那我从text1[i-1]不加入对比或者text2[j-1]不加入对比
    */
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(1001, vector<int>(1001, 0));
        int n1 = text1.size();
        int n2 = text2.size();
        int res = 0;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
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
