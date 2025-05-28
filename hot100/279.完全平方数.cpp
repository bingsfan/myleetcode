/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
	int numSquares(int n) {
        if(n==1) return 1;
		vector<int> nums;
		for(int i = 1; i < n; i++) {
			if(i * i <= n) {
				nums.push_back(i * i);
			}
		}
		// 装满背包大小为n的包，最少要用多少个物品
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for(auto &num : nums) {
			for(int bagsize = 1; bagsize <= n; bagsize++) {
				if(bagsize >= num && dp[bagsize - num] != INT_MAX) {
					dp[bagsize] = min(dp[bagsize], dp[bagsize - num] + 1);
				}
			}
		}
		return dp[n];
	}
};
// @lc code=end

