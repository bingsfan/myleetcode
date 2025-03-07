/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int res = INT32_MAX;
        int len = 0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while (sum>=target)
            {
                len = j-i+1;
                res = (res<len)?res:len;
                sum-=nums[i++];
            }
        }
        return res == INT32_MAX?0:res;
    }
};
// @lc code=end

