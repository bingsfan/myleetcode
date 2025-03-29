/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
  public:
    /*
    首先这题肯定是组合，然后要比较凑成的最少方法数
    dp[j] = dp[j] + dp[j-coins[i]]这是总的方法数
    左边的dp[j]其实代表着用前i-1个物品，不用coins[i],右边的dp[j-coins[i]]代表用coins[i]
    因此最少的方法数应该是dp[j] = min(dp[j],dp[j-coins[i]])
    那这里就不能初始化成0了，不然直接弄出来都是0，初始化都为最大值
    dp[0]=1


    操，看错了，是硬币个数不是方法数，初始化dp[0]=0，拿递推公式应该改成
    dp[j] = min(dp[j],dp[j-coins[i]]+1),这里value就是硬币的个数了
    */
    int coinChange(vector<int> &coins, int amount)
    {
        vector<uint64_t> dp(10001, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coins[i]]+1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end
