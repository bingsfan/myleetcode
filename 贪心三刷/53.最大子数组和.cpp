/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
  public:
    /*
    子数组要求连续，规定dp[i]是考虑了下标为0-i这么多元素，并且以nums[i]结尾的最大子数组的和
    一定要带上这个以nums[i]为结尾，dp[i]可以由两个状态转移而来,要取一个最大值
    1.dp[i-1]加nums[i]，比如前面的和是正数，nums[i]是个正数
    2.nums[i]，比如前面和是负数，nums[i]还是个复数，那就只能选这个
    从前往后遍历
    初始化：因为dp[i]有可能等于nums[i]，因此直接初始化成nums[i]，dp[0]=nums[0]没啥问题,也可光初始化一个0就够了
    要求的是最大子数组和，和哪个结尾没关系，所以需要用res找出dp数组的最大值返回
  */
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        int res = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = dp[i] > res ? dp[i] : res;
        }
        return res;
    }
};
// @lc code=end
