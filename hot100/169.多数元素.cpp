/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
	int majorityElement(vector<int> &nums) {
		unordered_map<int, int> umap;
		for(auto &num : nums) {
			umap[num]++;
		}
		int n = nums.size() / 2;
		for(auto &pli : umap) {
			if(pli.second > n) {
				return pli.first;
			}
		}
		return -1;
	}
};
// @lc code=end

