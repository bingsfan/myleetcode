/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
	bool exist(vector<vector<char>> &board, string word) {
		vector<pair<int, int>> dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> used(m, vector<bool>(n, false));
		string path;
		function<bool(int, int, int)> dfs = [&](int x, int y, int len) -> bool {
			if(path == word) {
				return true;
			}
			if(x < 0 || x >= m || y < 0 || y >= n || used[x][y] || board[x][y] != word[len]) {
				return false;
			}
			len += 1;
			used[x][y] = true;
			path.push_back(board[x][y]);
			for(auto &dir : dirs) {
				int nx = x + dir.first;
				int ny = y + dir.second;
				if(dfs(nx, ny, len)) {
					return true;
				}
			}
			len -= 1;
			used[x][y] = false;
			path.pop_back();
			return false;
		};
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(dfs(i, j, 0)) {
					return true;
				}
			}
		}
		return false;
	}
};
// @lc code=end

