/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution
{
  public:
  /*
    要求最长连续递增序列的长度，定义dp[i]为以nums[i]为结尾的最长连续递增序列的长度
    只要判断相邻的就行即判断nums[i]和nums[i-1],如果大于，则dp[i]=dp[i-1]+1
    要求最长的，其实就是目前dp数组中所有的最大值，返回值就是这个最大值
  */
    int findLengthOfLCIS(vector<int> &nums)
    {
        vector<int> dp(10001, 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = 1 + dp[i - 1];
            }
            if (dp[i] > res)
            {
                res = dp[i];
            }
        }
        return res;
    }
};
// @lc code=end
