/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
	void moveZeroes(vector<int> &nums) {
		// 使用快慢指针，也就是双指针方法
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
	}
};
// @lc code=end

