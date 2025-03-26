/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
  public:
    /*
    需要从左到右，从右到左遍历两次
    从左到右，找右大于左的情况，如果ratings[i]>ratings[i-1] candy[i]=candy[i-1]+1
    从右到左，找左大于右的情况
  */
    int candy(vector<int> &ratings)
    {
        vector<int> nums(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                nums[i] = nums[i-1]+1;
            }
        }
        for (int i = ratings.size()-1; i > 0; i--)
        {
            if (ratings[i] < ratings[i - 1])
            {
                nums[i - 1] = max(nums[i - 1], 1 + nums[i]);
            }
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
