/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution
{
  public:
    /*
    有障碍物了。首先有障碍物的这个点肯定dp[i][j]=0;
    另外如果初始化的时候最上侧和最左侧有障碍物，后面的也到不了了
  */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(101, vector<int>(101, 0));
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // 最左侧初始化
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                break;
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        // 最上边初始化
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
            {
                break;
            }
            else
            {
                dp[0][i] = 1;
            }
        }
        // 中间有障碍的还没有处理
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
