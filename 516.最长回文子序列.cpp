/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
    子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 */

// @lc code=start
class Solution {
public:
/* 
    dp数组定义：
        dp[i][j]表示[i,j]区间内字符串的最长回文子序列的长度
        返回值为dp[0][s.size()-1]
    递推公式：
        if(s[i]==s[j])
            dp[i][j]=dp[i+1][j-1]+2
        else
            dp[i][j]=max(dp[i][j-1],dp[i+1][j])
    遍历顺序：
        根据递推公式画坐标图，i应该从后往前遍历，j从前往后遍历
    初始化：
        dp[i][i]=1

*/
    int longestPalindromeSubseq(string s) {
        int n  = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=n;i>=0;i--){
            for(int j=i+1;j<n;j++){//因为是区间，并且i==j已经初始化过了
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

