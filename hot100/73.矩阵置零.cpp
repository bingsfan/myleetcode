/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
	void setZeroes(vector<vector<int>> &matrix) {
		int n = matrix.size();
        int m = matrix[0].size();
		// 使用矩阵的第一行和第一列来做标记
		bool rowHaveZero = false;
		bool colHaveZero = false;
		for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                rowHaveZero=true;
            }
        }
		for(int i = 0; i < n; ++i) {
			if(matrix[i][0] == 0)
				colHaveZero = true;
		}
		// 用第一行第一列做标记
		for(int i = 1; i < n; ++i) {
			for(int j = 1; j < m; ++j) {
				if(matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		// 根据标记置0
		for(int i = 1; i < n; ++i) {
			for(int j = 1; j < m; ++j) {
				if(matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		// 再处理第一行和第一列
		if(rowHaveZero) {
			for(int j = 0; j < m; j++) {
				matrix[0][j] = 0;
			}
		}
		if(colHaveZero) {
			for(int i = 0; i < n; i++) {
				matrix[i][0] = 0;
			}
		}
	}
};
// @lc code=end

