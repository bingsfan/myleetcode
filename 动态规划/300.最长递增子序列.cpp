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
    要求最长递增子序列，子序列是不连续的
    定义dp[i]为以nums[i]为结尾的最长递增子序列的长度
    如果nums[i]>nums[j],dp[i]=1 + dp[j],这个过程要重复多次，因此要留下最大的dp[i]
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
