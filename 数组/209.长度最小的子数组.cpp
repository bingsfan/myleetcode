/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:

/* 
    滑动窗口问题：
    i表示起始的位置，j表示窗口结束的位置，窗口长度为j-i+1;
    如果窗口内的元素总和已经大于target的，这时候起始位置就要开始移动
    一直移动到<target为止
*/
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        int sum=0;
        int i=0;//起始位置
        int len=0;//滑动窗口的长度
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while (sum>=target)
            {
                len=j-i+1;
                res=res<len?res:len;
                sum-=nums[i];
                i++;
            }
            
        }
        return res==INT_MAX?0:res;

    }
};
// @lc code=end

