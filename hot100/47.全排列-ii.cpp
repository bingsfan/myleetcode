/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback47(vector<int> &nums, vector<bool> &used) {
		if(path.size() == nums.size()) {
			res.push_back(path);
			return;
		}
		for(int i = 0; i < nums.size(); i++) {
			if(used[i]) {
				continue;
			}
			if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
				continue;
			}
			used[i] = true;
			path.push_back(nums[i]);
			traceback47(nums, used);
			used[i] = false;
			path.pop_back();
		}
	}
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		traceback47(nums, used);
		return res;
	}
};
// @lc code=end

