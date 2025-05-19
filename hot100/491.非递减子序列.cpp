/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback491(vector<int> &nums, int startIndex) {
		if(path.size() >= 2) {
			res.push_back(path);
		}
		unordered_set<int> uset;
		for(int i = startIndex; i < nums.size(); i++) {
			if(!path.empty() && nums[i] < path.back() || uset.count(nums[i])) {
				continue;
			}
			uset.insert(nums[i]);
			path.push_back(nums[i]);
			traceback491(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> findSubsequences(vector<int> &nums) {
		traceback491(nums, 0);
		return res;
	}
};
// @lc code=end

