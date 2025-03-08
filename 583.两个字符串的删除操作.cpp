/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

    每步可以删除任意一个字符串中的一个字符。
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
/* 
    首先想到的思路是求出两个字符串的公共子序列长度，然后两个字符串长度的和减去2倍公共子序列长度就行了
    定义dp数组：
        dp[i][j]:word1的前i个元素和word2的前j个元素的公共子序列长度为dp[i][j]
    递推公式
        if(word1[i-1]==word2[j-1])
            dp[i][j]=dp[i-1][j-1]+1
        else 有两种情况，这个就不用分大小集合了
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])
    初始化：
        都初始化成0
*/
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int res=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(dp[i][j]>res){
                    res = dp[i][j];
                }
            }
        }
        return n1+n2-res-res;
    }
};
// @lc code=end

