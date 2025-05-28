/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
	int search(vector<int> &nums, int target) {
		int n = nums.size();
		int l = 0, r = n - 1;
		while(l <= r) {
			int m = (l + r) / 2;
			if(nums[m] == target) {
				return m;
			} else if(nums[m] <= nums[r]) {
				if(nums[m] < target && target <= nums[r]) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			} else if(nums[m] >= nums[l]) {
				if(nums[l] <= target && target < nums[m]) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			}
		}
		return -1;
	}
};
// @lc code=end

