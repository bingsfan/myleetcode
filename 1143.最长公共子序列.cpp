/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    /*
        一般两个数组的问题使用二维dp数组定义
        dp[i][j]:nums1的前i个元素和nums2的前j个元素的公共子序列(不一定要连续了)的最大长度
        和上一道题类似，但是这个公共子序列不要求一定连续
        if(text1[i-1]==text[j-1])  dp[i][j]=dp[i-1][j-1]+1
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        初始化：
        dp[i][0]和dp[0][j]都是没有意义的，初始化成0，所有都初始化成0
        dp数组长度为两个size+1
        返回所有dp中最大的
    */
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2 = text2.size();
        vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
        int res= 0;
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if(dp[i][j]>res){
                    res=dp[i][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end

