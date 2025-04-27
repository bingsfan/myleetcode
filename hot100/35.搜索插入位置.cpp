/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
	int searchInsert(vector<int> &nums, int target) {
		int l = 0, r = nums.size();
		// l和r其实就是结果的范围了，插入可以是元素的最后
		// 应该要>=target的第一个位置
		while(l < r) {
			int m = l + (r - l) / 2;
			if(nums[m] >= target) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return l;
	}
};
// @lc code=end

