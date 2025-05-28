/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
	int lastStoneWeightII(vector<int> &stones) {
		int total = 0;
		for(auto &num : stones)
			total += num;
		int bagSize = total / 2;
		int n		= stones.size();
		vector<int> dp(bagSize + 1, 0);
		for(int i = 0; i < n; i++) {
			for(int j = bagSize; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		return total - dp[bagSize] - dp[bagSize];
	}
};
// @lc code=end

