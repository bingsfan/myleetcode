/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
	vector<pair<int, int>> dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	bool dfs(vector<vector<char>> &board, string word, string &path,
			 vector<vector<bool>> &visited, int x, int y, int len) {
		if(path == word) {
			return true;
		}
		int n = board.size(), m = board[0].size();
		if(x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || board[x][y] != word[len]) {
			return false;
		}
		path.push_back(board[x][y]);
		visited[x][y] = true;
		len++;
		for(auto &dir : dirs) {
			int nx = x + dir.first;
			int ny = y + dir.second;
			if(dfs(board, word, path, visited, nx, ny, len)) {
				return true;
			}
		}
		len--;
		path.pop_back();
		visited[x][y] = false;
		return false;
	}
	bool exist(vector<vector<char>> &board, string word) {
		// 要在board中找第一个字符等于word[0]的，从这里开始dfs，和岛屿问题有点像
		string path;
		int n = board.size(), m = board[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[0].size(); j++) {
				if(board[i][j] == word[0]) {
					path	= "";
					int len = 0;
					if(dfs(board, word, path, visited, i, j, len)) {
						return true;
					}
				}
			}
		}
		return false;
	}
};
// @lc code=end

