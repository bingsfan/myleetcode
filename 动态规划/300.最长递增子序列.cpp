/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution
{
  public:
    /*
    max(1+dp[j],dp[i]);这里求最大值求的是1+dp[j]的最大值
*/
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(5000, 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
                if (dp[i] > res)
                {
                    res = dp[i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
