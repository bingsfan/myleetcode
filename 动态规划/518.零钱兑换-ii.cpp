/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution
{
  public:
    /*
    核心是将amout用coins装满有多少种方法，coins里面的物品可以多次选，完全背包问题
    定义dp[i]：用coins装满背包容量为i的背包有dp[i]种方法
    dp[j] = dp[j]+dp[j-coins[i]]
    遍历顺序：先物品再背包，要去重，跑跑看
    初始化： dp[0]=1
  */
    int change(int amount, vector<int> &coins)
    {
        vector<uint64_t> dp(5001, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end
