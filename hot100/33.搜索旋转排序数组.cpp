/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
	int search(vector<int> &nums, int target) {
		int l = 0, r = nums.size() - 1;
		while(l <= r) {
			int m = (l + r) / 2;
			if(nums[m] == target) {
				return m;
			} else if(nums[m] >= nums[l]) {
				// 左侧有序,在左侧找target
				if(nums[m] > target && target >= nums[l]) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			} else if(nums[m] <= nums[r]) {
				// 右侧有序
				if(nums[m] < target && target <= nums[r]) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			}
		}
		return -1;
	}
};
// @lc code=end

