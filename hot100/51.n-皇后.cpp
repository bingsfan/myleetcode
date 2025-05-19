/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> board(n, string(n, '.'));
		auto isValid = [&](int row, int col) {
			for(int i = 0; i < n; i++) {
				if(board[i][col] == 'Q') {
					return false;
				}
			}
			// 看两个斜线
			int i = row - 1, j = col - 1;
			while(i >= 0 && j >= 0) {
				if(board[i][j] == 'Q') {
					return false;
				}
				i--, j--;
			}
			i = row - 1, j = col + 1;
			while(i >= 0 && j < n) {
				if(board[i][j] == 'Q') {
					return false;
				}
				i--, j++;
			}
			return true;
		};
		function<void(vector<string> &, int, int)> dfs = [&](vector<string> &board, int n,
															 int row) {
			if(row == n) {
				res.push_back(board);
				return;
			}
			for(int col = 0; col < n; col++) {
				if(isValid(row, col)) {
					board[row][col] = 'Q';
					dfs(board, n, row + 1);
					board[row][col] = '.';
				}
			}
		};
		dfs(board, n, 0);
		return res;
	}
};
// @lc code=end

