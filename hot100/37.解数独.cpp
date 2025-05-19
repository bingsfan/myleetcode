/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
	void solveSudoku(vector<vector<char>> &board) {
		auto isValid = [&](int row, int col, char val) {
			// 同一行有val
			for(int j = 0; j < 9; j++) {
				if(board[row][j] == val) {
					return false;
				}
			}
			// 同一列有val
			for(int i = 0; i < 9; i++) {
				if(board[i][col] == val) {
					return false;
				}
			}
			// 同一个3x3的小格子中有val
			int startRow = (row / 3) * 3;
			int startCol = (col / 3) * 3;
			for(int i = startRow; i < startRow + 3; i++) {
				for(int j = startCol; j < startCol + 3; j++) {
					if(board[i][j] == val) {
						return false;
					}
				}
			}
			return true;
		};
		function<bool()> dfs = [&]() {
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j < 9; j++) {
					if(board[i][j] == '.') {
						for(char k = '1'; k <= '9'; k++) {
							if(isValid(i, j, k)) {
								board[i][j] = k;
								if(dfs()) {
									return true;
								}
								board[i][j] = '.';
							}
						}
						return false;
					}
				}
			}
			return true;
		};
		dfs();
		return;
	}
};
// @lc code=end

