/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
	void traceback90(vector<int> &nums, int startIndex, vector<bool> &used) {
		res.push_back(path);
		for(int i = startIndex; i < nums.size(); i++) {
			if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
				continue;
			}
			path.push_back(nums[i]);
			used[i] = true;
			traceback90(nums, i + 1, used);
			used[i] = false;
			path.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		traceback90(nums, 0, used);
		return res;
	}
};
// @lc code=end

