/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback78(vector<int> &nums, int startIndex) {
		res.push_back(path);
		for(int i = startIndex; i < nums.size(); i++) {
			path.push_back(nums[i]);
			traceback78(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int> &nums) {
		if(nums.empty()) {
			return res;
		}
		traceback78(nums, 0);
		return res;
	}
};
// @lc code=end

