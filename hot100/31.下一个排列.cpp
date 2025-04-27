/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
	void nextPermutation(vector<int> &nums) {
		int n = nums.size();
		int i = n - 2;
		// Step 1: 找到第一个下降的位置 i，使得 nums[i] < nums[i+1]
		while(i >= 0 && nums[i] >= nums[i + 1]) {
			i--;
		}
		if(i >= 0) {
			// Step 2: 找到第一个比 nums[i] 大的数，从右往左找
			int j = n - 1;
			while(nums[j] <= nums[i]) {
				j--;
			}
			swap(nums[i], nums[j]);	   // 交换
		}
		// Step 3: 把 i+1 到末尾反转
		reverse(nums.begin() + i + 1, nums.end());
	}
};
// @lc code=end

