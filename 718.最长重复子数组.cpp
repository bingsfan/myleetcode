/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
/* 
    一般两个数组的问题使用二维dp数组定义
    dp[i][j]:nums1的前i个元素和nums2的前j个元素的公共子数组(一定是连续的)的最大长度
    if(nums[i-1]==nums[j-1]) dp[i][j]=dp[i-1][j-1]+1
*/
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int res = 0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                if(dp[i][j]>res) res=dp[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

