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
		dp.push_back({ 1 });
		if(numRows == 1)
			return dp;
		for(int i = 2; i <= numRows; i++) {
			vector<int> tmp(i, 1);
			for(int j = 1; j < i - 1; j++) {
				tmp[j] = dp.back()[j - 1] + dp.back()[j];
			}
			dp.push_back(tmp);
		}
		return dp;
	}
};
// @lc code=end

