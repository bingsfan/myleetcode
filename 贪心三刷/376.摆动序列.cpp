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
    当前节点要么是山峰，要么是山谷，分别用dp[i][0]和dp[i][1]分别定义
    dp[i][0]代表nums[i]是山峰，此时最长摆动子序列的重长度
    是子序列不是子数组，因此不要求连续
    dp[i][0]=max(dp[i][0],dp[j][1]+1)
    子序列至少长度都是1，初始化成全1

    这题我还是有点问题，没完全弄懂,调试完差不多了，不过这个思想我一下还想不出来，就是这种定义状态的
  */
    int wiggleMaxLength(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(2, 1));
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[i])
                { // 处理山谷的情况
                    dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
                }
            }
            for (int j = 0; j < i; j++)
            { // 处理山峰的情况
                if (nums[j] < nums[i])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
        }
        return max(dp[size - 1][0], dp[size - 1][1]);
    }
};
// @lc code=end
