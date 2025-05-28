/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
	int findTargetSumWays(vector<int> &nums, int target) {
		int total = 0;
		int n	  = nums.size();
		for(auto &num : nums) {
			total += num;
		}
		if((total + target) % 2 != 0) {
			return 0;
		}
		int bagSize = (total + target) / 2;
        if(bagSize<0){
            return 0;
        }
		vector<int> dp(bagSize + 1, 0);
		dp[0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = bagSize; j >= nums[i]; j--) {
				dp[j] += dp[j - nums[i]];
			}
		}
		return dp[bagSize];
	}
};
// @lc code=end

