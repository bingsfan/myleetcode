/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		int n = nums.size();
		unordered_map<int, int> umap;
		umap[0] = 1;
		int sum = 0;
		int res = 0;
		for(auto &num : nums) {
			sum += num;
			if(umap.count(sum - k)) {
				res += umap[sum - k];
			}
			umap[sum]++;
		}
		return res;
	}
};
// @lc code=end

