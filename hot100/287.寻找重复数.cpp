/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
	int findDuplicate(vector<int> &nums) {
		int slow = 0, fast = 0;
		slow = nums[slow];
		fast = nums[nums[fast]];
		while(slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		int pre1 = 0, pre2 = slow;
		while(pre1 != pre2) {
			pre1 = nums[pre1];
			pre2 = nums[pre2];
		}
		return pre2;
	}
};
// @lc code=end

