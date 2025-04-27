/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
	vector<int> productExceptSelf(vector<int> &nums) {
		// 分成两边分别处理
		int n = nums.size();
		vector<int> res(n);
		vector<int> left(n, 1);
		for(int i = 1; i < n; i++) {
			left[i] = left[i - 1] * nums[i - 1];
		}
		vector<int> right(n, 1);
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

