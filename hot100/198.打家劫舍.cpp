/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
	int rob(vector<int> &nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		dp[0] = { 0, nums[0] };
		for(int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + nums[i];
		}
		return max(dp[n - 1][0], dp[n - 1][1]);
	}
};
// @lc code=end

