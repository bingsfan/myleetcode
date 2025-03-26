/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        if(nums.size()==1) return true;
        int end = nums[0];
        for (int i = 0; i <= end; i++)
        {
            end = max(i + nums[i], end);
            if (end >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
