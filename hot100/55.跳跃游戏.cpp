/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
	bool canJump(vector<int> &nums) {
		int n	   = nums.size();
		int border = nums[0];
		for(int i = 0; i <= border; i++) {
			border = max(border, i + nums[i]);
			if(border >= n - 1) {
				return true;
			}
		}
		return false;
	}
};
// @lc code=end

