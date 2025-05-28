/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
	bool canPartition(vector<int> &nums) {
		int total = 0;
		int n	  = nums.size();
		for(auto &num : nums) {
			total += num;
		}
		if(total % 2 != 0) {
			return false;
		}
		int bagSize = total / 2;
		vector<int> dp(bagSize + 1, 0);
		for(int i = 0; i < n; i++) {
			for(int j = bagSize; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return dp[bagSize] == bagSize;
	}
};
// @lc code=end

