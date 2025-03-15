/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，
 * 返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 输入：nums = [-4,-1,0,3,10]
   输出：[0,1,9,16,100]
 */

// @lc code=start
/* 
    用双指针指向数组的两端，看两边的平方哪个大，大的就加入结果数组中，结果数组从后往前加
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        vector<int> res(right+1);
        int p=right;
        while (left<=right)
        {
            int squarel=nums[left]*nums[left];
            int squarer = nums[right] * nums[right];
            if(squarel>=squarer){
                res[p--]=squarel;
                left++;
            }else
            {
                res[p--]=squarer;
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

