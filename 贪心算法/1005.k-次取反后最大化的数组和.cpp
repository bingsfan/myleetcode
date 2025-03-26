/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
  public:
    // 先排序,从小到大,让负数先取反,取反完如果还有就对整数取反剩下的
    // 刚开始想错了，要对绝对值从大到小排序，然后先对负数进行处理，如果处理完负数还有k，那就对数组中的最后一个进行操作就行了
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) > abs(b); });
        for (int i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 != 0)
        {
            nums[nums.size() - 1] *= -1;
        }
        int res = 0;
        for (auto num : nums)
        {
            res += num;
        }
        return res;
    }
};
// @lc code=end
