/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
	vector<pair<int, int>> dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	void dfs_200(vector<vector<char>> &grid, int x, int y) {
		int m = grid.size(), n = grid[0].size();
		if(grid[x][y] == '0') {
			return;
		}
		grid[x][y] = '0';
		for(auto &[r, c] : dirs) {
			int nx = x + r;
			int ny = y + c;
			if(nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1) {
				continue;
			}
			dfs_200(grid, nx, ny);
		}
	}
	int numIslands(vector<vector<char>> &grid) {
		int m = grid.size(), n = grid[0].size();
		int res = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == '1') {
					res++;
					dfs_200(grid, i, j);
				}
			}
		}
		return res;
	}
};
// @lc code=end

