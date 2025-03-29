/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
  public:
    /*
    跟零钱兑换那道题差不多，都是用nums中的数，填满target有多少种方法，不过这个题是排列了
    需要先背包，后物品
    dp[j] += dp[j-nums[i]]
    因此j>=nums[i]的情况才执行上面的
  */

    int combinationSum4(vector<int> &nums, int target)
    {
        vector<uint64_t> dp(1001, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (j >= nums[i])
                {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
