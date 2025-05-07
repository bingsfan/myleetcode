/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// 从左下角开始搜索，这样能保证往右边是大，往上是小
		int n = matrix.size(), m = matrix[0].size();
		int i = n - 1, j = 0;
		while(i < n && j < m && i >= 0 && j >= 0) {
			if(matrix[i][j] == target) {
				return true;
			} else if(matrix[i][j] > target) {
				i--;
			} else {
				j++;
			}
		}
		return false;
	}
};
// @lc code=end

