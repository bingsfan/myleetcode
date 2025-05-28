/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
	/* int findMin(vector<int> &nums) {
		int l = 0, r = nums.size() - 1;
		int res = INT_MAX;
		while(l <= r) {
			int m = (l + r) / 2;
			if(nums[m] > nums[r]) {
				l = m + 1;
			} else {
				r = (r == m) ? m - 1 : m;
			}
		}
		return nums[l];
	} */
// 这个更好理解一点
	int findMin(vector<int> &nums) {
		int l = 0, r = nums.size() - 1;
		int res = nums[l];
		while(l <= r) {
			int m = l + (r - l) / 2;
			res	  = min(res, nums[m]);
			if(nums[m] > nums[r]) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		return res;
	}
};
// @lc code=end

