/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
	int searchInsert(vector<int> &nums, int target) {
		int l = 0, r = nums.size() - 1;
		while(l <= r) {
			int m = (l + r) / 2;
			if(nums[m] >= target) {
				r = (r == m) ? m - 1 : m;
			} else {
				l = m + 1;
			}
		}
		return l;
	}
};
// @lc code=end

