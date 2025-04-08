/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
  public:
    /*
    要求最大子数组的和
    定义dp[i]为以nums[i]为结尾的最大子数组的和
    dp[i] = max(dp[i-1]+nums[i],nums[i])
    一个是之前的加上现在的，和现在的值做对比,要求dp数组里面的最大值
    dp[0]=nums[0];
*/
    int maxSubArray(vector<int> &nums)
    {
        int n1 = nums.size();
        vector<int> dp(n1 + 1, 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n1; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > res)
            {
                res = dp[i];
            }
        }
        return res;
    }
};
// @lc code=end
