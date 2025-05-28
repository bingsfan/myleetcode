/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
	int combinationSum4(vector<int> &nums, int target) {
		vector<uint64_t> dp(target + 1, 0);
		dp[0] = 1;
		for(int bagsize = 1; bagsize <= target; bagsize++) {
			for(auto &num : nums) {
				if(bagsize >= num) {
					dp[bagsize] += dp[bagsize - num];
				}
			}
		}
		return dp[target];
	}
};
// @lc code=end

