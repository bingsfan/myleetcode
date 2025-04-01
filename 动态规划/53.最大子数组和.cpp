/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(100001);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            if (dp[i] > res)
            {
                res = dp[i];
            }
        }
        return res;
    }
};
// @lc code=end
