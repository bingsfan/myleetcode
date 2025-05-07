/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
		int n = nums.size();
		// dp[i]是以nums[i]为最后一个元素的最大子数组和
		vector<int> dp(n,0);
		dp[0]=nums[0];
		int res = dp[0];
		for(int i=1;i<n;i++){
			dp[i]=max(dp[i-1]+nums[i],nums[i]);
			res = max(res,dp[i]);
		}
		return res;
	}
};
// @lc code=end

