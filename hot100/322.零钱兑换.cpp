/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
	int coinChange(vector<int> &coins, int amount) {
		int bagsize = amount;
        if(amount==0) return 0;
		if(coins.size() == 1 && coins[0] > amount) {
			return -1;
		}
		vector<int> dp(bagsize + 1, INT_MAX);
		dp[0] = 0;
		for(int j = 1; j <= bagsize; j++) {
			for(auto &num : coins) {
				if(j >= num && dp[j - num] != INT_MAX) {
					dp[j] = min(dp[j], dp[j - num] + 1);
				}
			}
		}
		if(dp[bagsize] == INT_MAX) {
			return -1;
		}
		return dp[bagsize];
	}
};
// @lc code=end

