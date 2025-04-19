/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n	= s.size();
		int res = 1;
		if(n == 0)
			return 0;
		vector<int> dp(n, 1);
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < i; j++) {
				if(s[i] == s[j]) {
					dp[i] = dp[i - 1];
					break;
				} else {
					dp[i] = dp[i - 1] + 1;
				}
			}
			if(dp[i] > res) {
				res = dp[i];
			}
		}
		return res;
	}
};
// @lc code=end

