/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> dp;
		if(numRows == 1) {
			return { { 1 } };
		} else if(numRows == 2) {
			return { { 1 }, { 1, 1 } };
		}
		dp.push_back({ 1 });
		dp.push_back({ 1, 1 });
		for(int row = 3; row <= numRows; row++) {
			vector<int> tmp(row, 1);
			for(int j = 1; j < row - 1; j++) {
				tmp[j] = dp[row - 2][j] + dp[row - 2][j - 1];
			}
			dp.push_back(tmp);
		}
		return dp;
	}
};
// @lc code=end

