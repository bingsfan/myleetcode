/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string path;
		function<void(int, int)> dfs = [&](int l, int r) {
			if(path.size() == n * 2) {
				res.push_back(path);
			}
			if(l < n) {
				path.push_back('(');
				dfs(l + 1, r);
				path.pop_back();
			}
			if(r < l) {
				path.push_back(')');
				dfs(l, r + 1);
				path.pop_back();
			}
		};
		dfs(0, 0);
		return res;
	}
};
// @lc code=end

