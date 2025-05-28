/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
	int findKthLargest(vector<int> &nums, int k) {
		int n								= nums.size();
		int k_smallest						= n - k;
		function<int(int, int)> quickSelect = [&](int l, int r) {
			if(l == r) {
				return nums[l];
			}
			// 分成三路，可以解决重复元素过多的问题
			int lt = l, gt = r, i = l;
			int pivot = nums[r];
			while(i <= gt) {
				if(nums[i] < pivot) {
					swap(nums[lt], nums[i]);
					lt++, i++;
				} else if(nums[i] > pivot) {
					swap(nums[gt], nums[i]);
					gt--;
				} else {
					i++;
				}
			}
			if(k_smallest < lt) {
				return quickSelect(l, lt - 1);
			} else if(k_smallest > gt) {
				return quickSelect(gt + 1, r);
			} else {
				return nums[k_smallest];
			}
		};
		return quickSelect(0, n - 1);
	}
};
// @lc code=end

