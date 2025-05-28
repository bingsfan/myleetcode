/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int n = nums.size();
		int l = 0, r = n - 1;
		auto leftBorder = [&]() {
			l = 0, r = n - 1;
			while(l <= r) {
				int m = (l + r) / 2;
				if(nums[m] >= target) {
					r = (r == m) ? m - 1 : m;
				} else {
					l = m + 1;
				}
			}
			if(l == n || nums[l] != target) {
				return -1;
			}
			return l;
		};
		auto rightBorder = [&]() {
			l = 0, r = n - 1;
			while(l <= r) {
				int m = (l + r) / 2;
				if(nums[m] > target) {
					r = (r == m) ? m - 1 : m;
				} else {
					l = m + 1;
				}
			}
			if(r < 0 || nums[r] != target) {
				return -1;
			}
			return r;
		};
		int lb = leftBorder();
		int rb = rightBorder();
		return { lb, rb };
	}
};
// @lc code=end

