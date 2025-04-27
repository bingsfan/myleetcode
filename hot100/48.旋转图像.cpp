/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		// 先将矩阵转置,再对每一行reverse
		int n = matrix.size();
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for(int i = 0; i < n; i++) {
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};
// @lc code=end

