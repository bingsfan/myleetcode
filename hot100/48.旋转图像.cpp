/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		// 只需要将对矩阵转置,再每一行reverse就行了
		int n = matrix.size(), m = matrix[0].size();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for(int i = 0; i < n; i++) {
			reverse(matrix[i].begin(), matrix[i].end());
		}
		return;
	}
};
// @lc code=end

