/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> path;
		function<void(int)> dfs = [&](int startIndex) {
			if(path.size() == k) {
				res.push_back(path);
				return;
			}
			for(int i = startIndex; n - i + 1 + path.size() >= k; i++) {
				path.push_back(i);
				dfs(i + 1);
				path.pop_back();
			}
		};
		dfs(1);
		return res;
	}
};
// @lc code=end

