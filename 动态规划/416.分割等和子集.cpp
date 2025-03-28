/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
{
  public:
    /*
    背包的容量bagsize实际上是sum/2,如果sum%2!=0直接return false；
    如果bagsize能被nums里面的东西装满，就return true
    其实是判断dp[bagsize]==bagsize

    dp数组含义？容量为j的背包能装的最大价值
    这个里面的价值其实就是nums[i]，重量也是nums[i]
    dp[j]=max(dp[j],dp[j-nums[i]]+nums[i])

    dp初始化：dp[0]=0
  */
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        int bagSize = sum / 2;
        if (sum % 2 != 0)
        {
            return false;
        }

        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[bagSize] == bagSize;
    }
};
// @lc code=end
