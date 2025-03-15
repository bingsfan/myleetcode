/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
 * 请你找出给定目标值在数组中的开始位置和结束位置。
    如果数组中不存在目标值 target，返回 [-1, -1]。
    输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
 */

// @lc code=start
/* 
    这个题主要是解决了二分查找求上下边界的问题
    如果求出来的上下边界left>=right说明元素是在数组中存在的
    如果left<right说明数组中不存在target
    并且下界一般是元素应该插入的位置
*/

class Solution {
public:
    int leftBorder(vector<int> &nums, int target)
    {
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
    int rightBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left - 1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int left = leftBorder(nums, target);
        int right = rightBorder(nums, target);
        if (left > right)
            return {-1, -1};
        return {left, right};
    }
};
// @lc code=end

