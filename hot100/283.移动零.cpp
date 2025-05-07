/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
	void moveZeroes(vector<int> &nums) {
		// 快指针如果遇到非0，nums[slow]=nums[fast]
		int slow = 0;
		int n	 = nums.size();
		for(int fast = 0; fast < n; fast++) {
			if(nums[fast] != 0) {
				nums[slow++] = nums[fast];
			}
		}
		while(slow < n) {
			nums[slow++] = 0;
		}
		return;
	}
};
// @lc code=end

