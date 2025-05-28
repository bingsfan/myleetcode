/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		// 1、从后往前找第一个上升点
		int n = nums.size();
		int pivot, j;
		for(int i = n - 1; i > 0; i--) {
			if(nums[i] > nums[i - 1]) {
				pivot = i - 1;
				break;
			}
		}
		for(int i = n - 1; i > 0; i--) {
			if(nums[i] > nums[pivot]) {
				j = i;
				break;
			}
		}
		swap(nums[pivot], nums[j]);
		reverse(nums.begin() + pivot + 1, nums.end());
		return;
	}
};
// @lc code=end

