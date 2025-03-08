/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
    你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符
 */

// @lc code=start
class Solution {
/* 
    定义dp[i][j]:
        word1的前i个字符转换成word2的前j个字符最少需要dp[i][j]步
    递推公式：
        if(word1[i-1]==word2[j-1])
            dp[i][j] = dp[i-1][j-1] 不需要操作了
        else
            考虑删除和替换就行了,取三个操作的最小值
            删除：
            dp[i][j] = dp[i-1][j]+1
            dp[i][j] = dp[i][j-1]+1
            替换：
            dp[i][j] = dp[i-1][j-1]+1
    初始化：
        dp[i][0] word1需要删除i次
        dp[0][j] word2需要删除j次
    结果
    dp[n1][n2]

*/
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++) dp[i][0]=i;
        for(int i=0;i<=n2;i++) dp[0][i]=i;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        return dp[n1][n2];

    }
};
// @lc code=end

