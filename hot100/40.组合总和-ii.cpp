/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback40(vector<int> &candidates, int target, int sum, int startIndex,
					 vector<bool> &used) {
		if(sum == target) {
			res.push_back(path);
			return;
		}
		for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			if(i >= 1 && candidates[i] == candidates[i - 1] && used[i-1] == false) {
				continue;
			}
			path.push_back(candidates[i]);
			sum += candidates[i];
			used[i] = true;
			traceback40(candidates, target, sum, i+1, used);
			sum -= candidates[i];
			used[i] = false;
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<bool> used(candidates.size(), false);
		traceback40(candidates, target, 0, 0, used);
		return res;
	}
};
// @lc code=end

