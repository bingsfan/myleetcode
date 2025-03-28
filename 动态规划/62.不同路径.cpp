/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
  public:
    /*
    很明显起始点是(0,0),终止位置是(m-1,n-1)
    当前节点是(i,j),只能从上方(i-1,j)或者左方(i,j-1)移动而来
    定义dp[i,j]是从起点到达(i,j)的路径数，dp[i][j]=dp[i-1][j]+dp[i][j-1]
    初始化：
        最上面和最左侧只有一种方法能到达，因此统一初始化成1
  */
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(101, vector<int>(101, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
