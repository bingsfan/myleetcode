/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
  public:
    /*
    定义dp[i]为到达第i阶楼梯的最小花费
    dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
    因为可以从0或1开始，因此初始化都为0就行
    返回值是dp[size]
  */
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(1001, 0);
        int size = cost.size();
        for (int i = 2; i <= size; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }
};
// @lc code=end
