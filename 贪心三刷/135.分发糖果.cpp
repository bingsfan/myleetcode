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
    首先初始化每个人都得有一个糖，得从左到右，从右到左遍历两次
    从左到右解决，右边比左边大的，这样可以用到左边更新过的值
    从右到左解决，左边比右边大的，这样可以用到右边更新过的值
  */
    int candy(vector<int> &ratings)
    {
        // 每个人来一颗先
        int size = ratings.size();
        vector<int> nums(size, 1);
        // 左到右
        for (int i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                nums[i] = nums[i - 1] + 1;
            }
        }
        // 右到左
        for (int i = size - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                nums[i] = max(1 + nums[i + 1], nums[i]);
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
