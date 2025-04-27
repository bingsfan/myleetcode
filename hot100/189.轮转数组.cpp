/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
	void rotate(vector<int> &nums, int k) {
		// 先反转整个数组，再反转两个子数组
        int n = nums.size();
        k=k%n;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};
// @lc code=end

