/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		// 使用一个map，存储数值和下标，因为最后返回要的是下标
		unordered_map<int, int> umap;
		vector<int> res;
		int n = nums.size();
		for(int i = 0; i < n; i++) {
			umap[nums[i]] = i;
		}
		for(int i = 0; i < n; i++) {
			int a = nums[i];
			int b = target - nums[i];
			if(umap.count(b) && i != umap[b]) {
				return { i, umap[b] };
			}
		}
		return {};
	}
};
// @lc code=end

