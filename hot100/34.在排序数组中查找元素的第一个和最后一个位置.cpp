/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
/* 	int lowerBound(vector<int> &nums, int target) {
		// 如果找到了，还要继续向左找
		int l = 0, r = nums.size();
		while(l < r) {
			int m = (r + l) / 2;
			if(nums[m] >= target) {
				// mid>=target,要继续向左边去找
				r = m;
			} else {
				l = m + 1;
			}
		}
		if(l == nums.size() || nums[l] != target) {
			return -1;
		}
		return l;
	}
	int upBound(vector<int> &nums, int target) {
		int l = 0, r = nums.size();
		while(l < r) {
			int m = (l + r) / 2;
			if(nums[m] > target) {
				r = m;
			} else {
				// 小于等于还要继续向右边去找
				l = m + 1;
			}
		}
		if(l == 0 || nums[l - 1] != target) {
			return -1;
		}
		return l - 1;
	} */
/* 	vector<int> searchRange(vector<int> &nums, int target) {
		int lb = lowerBound(nums, target);
		int rb = upBound(nums, target);
		return { lb, rb };
	} */
	int leftBorder(vector<int> &nums, int target) {
		int l = 0, r = nums.size() - 1;
		// 要在nums中找>=target的第一个位置
		while(l <= r) {
			int m = (l + r) / 2;
			if(nums[m] >= target) {
				r = (r == m) ? m - 1 : m;
			} else {
				l = m + 1;
			}
		}
		if(l == nums.size() || nums[l] != target) {
			return -1;
		}
		return l;
	}
	int rightBorder(vector<int> &nums, int target) {
		int l = 0, r = nums.size() - 1;
		// 要在nums中找>target的第一个位置
		while(l <= r) {
			int m = (l + r) / 2;
			if(nums[m] > target) {
				r = (r == m) ? m - 1 : m;
			} else {
				l = m + 1;
			}
		}
		if(l == 0 || nums[l - 1] != target) {
			return -1;
		}
		return l-1;
	}
	vector<int> searchRange(vector<int> &nums, int target) {
		int lb = leftBorder(nums, target);
		int rb = rightBorder(nums, target);
		return { lb, rb };
	}
};
// @lc code=end
