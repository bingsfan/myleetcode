/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
  public:
    /*
    这题勾八和上面那个基本一模一样，不过要自己造一个nums数组
  */
    int numSquares(int n)
    {
        vector<int> nums;
        for (int i = 1; i * i <= n; i++)
        {
            nums.push_back(i * i);
        }

        vector<int> dp(10001, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = nums[i]; j <= n; j++)
            {
                dp[j] = min(dp[j], dp[j - nums[i]]+1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
