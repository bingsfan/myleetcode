/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution
{
  public:
    /*
    和分割等和子集很像，先想办法构建出来背包
    原先的数组被分成两块，其中一块就是背包，同样先求出来sum
    bagSize = sum/2;   2*bagSize<=sum
    dp[bagSize]是装在背包里的东西，sum-dp[bagSize]是没有装在背包中的东西
    这两块的差值就是最后的结果了把
  */
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (auto num : stones)
        {
            sum += num;
        }
        int bagSize = sum / 2;
        vector<int> dp(1501, 0);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = bagSize; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[bagSize] - dp[bagSize];
    }
};
// @lc code=end
