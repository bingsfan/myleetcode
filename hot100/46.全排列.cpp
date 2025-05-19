/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> permute(vector<int> &nums) {
		int n = nums.size();
		vector<bool> used(n, false);
		vector<int> path;
		vector<vector<int>> res;
		function<void(vector<int> &, vector<bool> &)> traceback = [&](vector<int> &nums,
																	  vector<bool> &used) {
			if(path.size() == nums.size()) {
				res.push_back(path);
				return;
			}
			for(int i = 0; i < nums.size(); i++) {
				if(used[i]) {
					continue;
				}
				path.push_back(nums[i]);
				used[i] = true;
				traceback(nums, used);
				path.pop_back();
				used[i] = false;
			}
		};
		traceback(nums, used);
		return res;
	}
};
// @lc code=end

