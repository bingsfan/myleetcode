/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
	int findLength(vector<int> &nums1, vector<int> &nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		int res = 0;
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
		for(int i = 1; i <= n1; i++) {
			for(int j = 1; j <= n2; j++) {
				if(nums1[i - 1] == nums2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
					res		 = max(res, dp[i][j]);
				}
			}
		}
		return res;
	}
};
// @lc code=end

