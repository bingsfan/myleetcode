/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
	vector<pair<int, int>> dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	typedef pair<int, int> Orange;
	int orangesRotting(vector<vector<int>> &grid) {
		queue<Orange> que;
		int m	  = grid.size();
		int n	  = grid[0].size();
		int res	  = -1;
		int fresh = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == 2) {
					que.push({ i, j });
				} else if(grid[i][j] == 1) {
					fresh++;
				}
			}
		}
		if(fresh == 0) {
			return 0;
		}
		while(!que.empty()) {
			int size = que.size();
			res++;
			for(int i = 0; i < size; i++) {
				Orange top = que.front();
				que.pop();
				int x = top.first, y = top.second;
				for(auto &[r, c] : dirs) {
					int nx = x + r;
					int ny = y + c;
					if(nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || grid[nx][ny] != 1) {
						continue;
					}
					grid[nx][ny] = 2;	 // 标记为腐烂
					que.push({ nx, ny });
					fresh--;
				}
			}
		}
		if(fresh != 0) {
			return -1;
		}
		return res;
	}
};
// @lc code=end
