/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 输入: nums = [1,3,5,6], target = 2
输出: 1
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 找的是下界
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return right + 1;
    }
};
// @lc code=end

