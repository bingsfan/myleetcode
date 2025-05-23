/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  
 * 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else{
                return mid;
            }
        }
        // 没有找到，返回-1
        return -1;
        
    }
};
// @lc code=end

