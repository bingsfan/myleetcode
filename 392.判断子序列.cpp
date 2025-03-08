/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
/* 
    dp[i][j]:s的前i个元素和t的前j个元素，相同子序列的长度
    如果相等：直接用上了
    如果不相等，因为s小而t大，缩小t去找s
    要求判断s是不是t的子序列，s是更小的集合
    因此只要dp[s.size][t.size]==s.size就是
*/
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        if(dp[n1][n2]==n1){
            return true;
        }
        return false;
    }
};
// @lc code=end

