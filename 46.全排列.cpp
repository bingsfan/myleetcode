/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback46(vector<int> &nums, vector<bool> &used) {
		if(path.size() == nums.size()) {
			res.push_back(path);
		}
		for(int i = 0; i < nums.size(); i++) {
			if(used[i]) {
				continue;
			}
			path.push_back(nums[i]);
			used[i] = true;
			traceback46(nums, used);
			used[i] = false;
			path.pop_back();
		}
	}
	vector<vector<int>> permute(vector<int> &nums) {
		int n = nums.size();
		vector<bool> used(n, false);
		traceback46(nums, used);
		return res;
	}
};
// @lc code=end

