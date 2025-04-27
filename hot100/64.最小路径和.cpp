/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
	int minPathSum(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = grid[0][0];
		// 初始化最上面那条边
		for(int i = 1; i < m; i++) {
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}
		// 初始化最左侧那条边
		for(int i = 1; i < n; i++) {
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		// 计算dp数组的值
		for(int i = 1; i < n; i++) {
			for(int j = 1; j < m; j++) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[n - 1][m - 1];
	}
};
// @lc code=end

