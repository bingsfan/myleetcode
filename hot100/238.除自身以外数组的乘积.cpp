/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
	vector<int> productExceptSelf(vector<int> &nums) {
		// 使用两个额外的数组，用来记录当前元素左边所有元素乘积和右边所有元素乘积，不包含当前元素
		int n = nums.size();
		vector<int> left(n, 1), right(n, 1), res(n);
		for(int i = 1; i < n; i++) {
			left[i] = left[i - 1] * nums[i - 1];
		}
		for(int i = n - 2; i >= 0; i--) {
			right[i] = right[i + 1] * nums[i + 1];
		}
		for(int i = 0; i < n; i++) {
			res[i] = left[i] * right[i];
		}
		return res;
	}
};
// @lc code=end

