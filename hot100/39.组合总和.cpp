/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback39(vector<int> &candidates, int target, int sum, int startIndex) {
		if(sum == target) {
			res.push_back(path);
			return;
		}
		for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			path.push_back(candidates[i]);
			sum += candidates[i];
			traceback39(candidates, target, sum, i);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		traceback39(candidates, target, 0, 0);
		return res;
	}
};
// @lc code=end

