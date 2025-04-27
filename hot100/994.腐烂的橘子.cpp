/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
	typedef pair<int, int> coord;
	int orangesRotting(vector<vector<int>> &grid) {
		// 统计有多少个新鲜的橘子和腐烂的橘子，腐烂的橘子直接加入队列当中
		queue<coord> que;
		int fresh = 0;
		int n = grid.size(), m = grid[0].size();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(grid[i][j] == 1) {
					fresh++;
				} else if(grid[i][j] == 2) {
					que.push({ i, j });
				}
			}
		}
		int time = 0;
		if(fresh == 0)
			return 0;
		vector<coord> dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		while(!que.empty()) {
			int size	  = que.size();
			bool infected = false;
			for(int i = 0; i < size; i++) {
				auto [x, y] = que.front();
				que.pop();
				for(auto [dx, dy] : dirs) {
					int nx = x + dx;
					int ny = y + dy;
					if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) {
						continue;
					}
					grid[nx][ny] = 2;
					fresh--;
					que.push({ nx, ny });
					infected = true;
				}
			}
			if(infected) {
				time++;
			} else {
				break;
			}
		}
		if(fresh == 0) {
			return time;
		}
		return -1;
	}
};
// @lc code=end

