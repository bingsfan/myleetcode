/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
	int findMaxForm(vector<string> &strs, int m, int n) {
		int bagsize1 = m;
		int bagsize2 = n;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		auto count0 = [&](string str) {
			int res = 0;
			for(auto &c : str) {
				if(c == '0')
					res++;
			}
			return res;
		};
		auto count1 = [&](string str) {
			int res = 0;
			for(auto &c : str) {
				if(c == '1')
					res++;
			}
			return res;
		};
		for(string &obj : strs) {
			int w0 = count0(obj);
			int w1 = count1(obj);
			for(int i = bagsize1; i >= w0; i--) {
				for(int j = bagsize2; j >= w1; j--) {
					dp[i][j] = max(dp[i][j], 1 + dp[i - w0][j - w1]);
				}
			}
		}
		return dp[bagsize1][bagsize2];
	}
};
// @lc code=end

