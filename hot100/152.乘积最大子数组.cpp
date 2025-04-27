/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
	int maxProduct(vector<int> &nums) {
		int n = nums.size();
		vector<int> dp_max(n, 0);
		vector<int> dp_min(n, 0);
		dp_max[0] = nums[0];
		dp_min[0] = nums[0];
		int res	  = nums[0];
		for(int i = 1; i < n; i++) {
			dp_max[i] = max({ dp_max[i - 1] * nums[i], nums[i], dp_min[i - 1] * nums[i] });
			dp_min[i] = min({ dp_min[i - 1] * nums[i], nums[i], dp_max[i - 1] * nums[i] });
			res		  = res > dp_max[i] ? res : dp_max[i];
		}
		return res;
	}
};
// @lc code=end

