/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
/* 
    只有一个数字，定义dp[i]为以nums[i]为结尾的子序列的最大和
    nums[i]要么可以加入，要么加不进去就得从头计算
    即dp[i-1]+nums[i]和Nums[i]，取最大值
    初始化：
    dp[0]=nums[0],其他初始化0就行
*/
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1) return nums[0];
    //     vector<int> dp(n,0);
    //     dp[0]=nums[0];
    //     int res = nums[0];
    //     for(int i=1;i<n;i++){
    //         dp[i]=max(dp[i-1]+nums[i],nums[i]);
    //         if(dp[i]>res) res=dp[i];
    //     }
    //     return res;
    // }
    /*
    dp[i]表示考虑前i+1个数，以nums[i]为结尾的最大子数组的和
    写的有点问题，因为子数组要连续的
*/
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.begin(), nums.end());
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i], dp[i - 1] + nums[i]);
            if (dp[i] > res)
            {
                res = dp[i];
            }
        }
        return res;
    }
};
// @lc code=end

