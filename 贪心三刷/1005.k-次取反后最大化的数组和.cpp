/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
  public:
    /*
    要按照绝对值排序
  */
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) { return abs(a) > abs(b); });
        int i;
        for (i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1)
        {
            nums.back() *= -1;
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
