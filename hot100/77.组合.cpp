/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback77(int n, int k, int cur) {
		if(path.size() == k) {
			res.push_back(path);
			return;
		}
		for(int i = cur; n - i + 1 + path.size() >= k; i++) {
			path.push_back(i);
			traceback77(n, k, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		traceback77(n, k, 1);
		return res;
	}
};
// @lc code=end

