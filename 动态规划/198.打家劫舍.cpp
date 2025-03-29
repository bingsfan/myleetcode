/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
  public:
    /*
      dp[i][0]:第i个房间没有被偷的最高金额
      第i个没被偷，那i-1可以被偷，i-1也可以不被偷，选这两的最大值
      dp[i][1]:第i个房间被偷了的最高金额
      第i个被偷了，那i-1就不能被偷，i-2可以偷，应该不用考虑i-2了，直接考虑i-1就行了
      dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
      dp[i][1] = dp[i-1][0]+nums[i]
      */
    int rob(vector<int> &nums)
    {
        vector<vector<int>> dp(101, vector<int>(2, 0));
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
// @lc code=end
