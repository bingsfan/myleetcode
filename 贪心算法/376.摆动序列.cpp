/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
  public:
    /*
    dp[i][0]考虑前i+1个数，下标为i作为作为最高点的摆动子序列的最长长度
    dp[i][1]考虑前i+1个数，下标为i作为作为最低点的摆动子序列的最长长度

  */
    int wiggleMaxLength(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(2, 1));
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (nums[i] < nums[j])
                {
                    dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
                }
            }
        }
        return max(dp[size - 1][0], dp[size - 1][1]);
    }
};
// @lc code=end
