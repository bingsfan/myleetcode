/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		int n = matrix.size(), m = matrix[0].size();
		int left = 0, top = 0, right = m - 1, bottom = n - 1;
		vector<int> res;
		while(left <= right && top <= bottom) {
			for(int j = left; j <= right; j++) {
				res.push_back(matrix[top][j]);
			}
			top++;
			for(int i = top; i <= bottom; i++) {
				res.push_back(matrix[i][right]);
			}
			right--;
			if(top <= bottom) {
				for(int j = right; j >= left; j--)
					res.push_back(matrix[bottom][j]);
				bottom--;
			}
			if(left <= right) {
				for(int i = bottom; i >= top; i--) {
					res.push_back(matrix[i][left]);
				}
				left++;
			}
		}
		return res;
	}
};
// @lc code=end

