/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
	void setZeroes(vector<vector<int>> &matrix) {
		// 使用矩阵的第一行和第一列来表示下面的是否有零，但是得额外记录第一行或者第一列是否有零，最后再处理
		int n = matrix.size(), m = matrix[0].size();
		bool rowHave0 = false, colHave0 = false;
		for(int j = 0; j < m; j++) {
			if(matrix[0][j] == 0) {
				rowHave0 = true;
			}
		}
		for(int i = 0; i < n; i++) {
			if(matrix[i][0] == 0) {
				colHave0 = true;
			}
		}
		// 统计0,用第一行和第一列来标识
		for(int i = 1; i < n; i++) {
			for(int j = 1; j < m; j++) {
				if(matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		// 给矩阵置零
		for(int i = 1; i < n; i++) {
			for(int j = 1; j < m; j++) {
				if(matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		// 如果第一行和第一列原先也有0，给他们都变成0
		if(rowHave0) {
			for(int j = 0; j < m; j++) {
				matrix[0][j] = 0;
			}
		}
		if(colHave0) {
			for(int i = 0; i < n; i++) {
				matrix[i][0] = 0;
			}
		}
		return;
	}
};
// @lc code=end

