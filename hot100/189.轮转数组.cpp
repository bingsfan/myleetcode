/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
	void rotate(vector<int> &nums, int k) {
		// 先对整个数组reverse，然后分两块reverse
        // !注意要先取模，k可能大于nums的长度
        k=k%(nums.size());
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
		return;
	}
};
// @lc code=end

