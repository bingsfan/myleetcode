/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
	int findLengthOfLCIS(vector<int> &nums) {
		int n = nums.size();
		vector<int> dp(n, 1);
		int res = 1;
		for(int i = 1; i < n; i++) {
			if(nums[i] > nums[i - 1]) {
				dp[i] = max(dp[i], 1 + dp[i - 1]);
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};
// @lc code=end

