/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
  public:
    /*
    将nums分成正数和负数的集合，如果可以凑成target
    正+负=sum
    正-负=target
    因此正=(sum+target)/2,其实这就是背包的size，但是这个题要的是凑成target的方法数
    dp[j]+=dp[j-nums[i]]
    初始化：
        dp[0]=1试试,这个还没弄懂为啥
    少写了两种极端情况
        如果target的绝对值比sum还大，直接return
        如果sum+target不是2的倍数，也不行
  */
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if(abs(target)>sum) return 0;
        if((sum + target) % 2!=0){
            return 0;
        }
        int bagSize = (sum + target) / 2;
        vector<int> dp(1501, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
// @lc code=end
