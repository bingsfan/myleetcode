/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
	int change(int amount, vector<int> &coins) {
		int n = coins.size();
		vector<uint64_t> dp(amount + 1, 0);
		int bagsize = amount;
		// 用coins中的coin装满bagsize有多少种不同的方法
		dp[0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= bagsize; j++) {
				if(j >= coins[i]) {
					dp[j] += dp[j - coins[i]];
				}
			}
		}
		return dp[amount];
	}
};
// @lc code=end

