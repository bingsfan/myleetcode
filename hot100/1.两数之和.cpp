/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> umap;
		vector<int> res;
		// key一定是下标，因为这样才唯一
		// !不要先hash，应该跟前缀和一样，一遍添加一遍计算，nums里面的值重复的话，map位置会被覆盖
		for(int i = 0; i < nums.size(); i++) {
			int a = nums[i], b = target - a;
			if(umap.count(b)) {
				res = { umap[b], i };
				break;
			} else {
				umap[a] = i;
			}
		}
		return res;
	}
};
// @lc code=end

