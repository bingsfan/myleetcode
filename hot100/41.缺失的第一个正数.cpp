/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
	int firstMissingPositive(vector<int> &nums) {
		int n = nums.size();
		// i的位置应该放i+1
		for(int i = 0; i < n; i++) {
			while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		// 找第一个不满足nums[i]=i+1的
		for(int i = 0; i < n; i++) {
			if(nums[i] != i + 1) {
				return i + 1;
			}
		}
		// 全都是正确的位置
		return n + 1;
	}
};
// @lc code=end

