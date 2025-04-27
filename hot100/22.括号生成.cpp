/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
	vector<string> res;
	void traceback(int left, int right, int n, string &path) {
		if(path.size() == n * 2) {
			res.push_back(path);
		}
		if(left < n) {
			path.push_back('(');
			left++;
			traceback(left, right, n, path);
			left--;
			path.pop_back();
		}
		if(right < left) {
			path.push_back(')');
			right++;
			traceback(left, right, n, path);
			right--;
			path.pop_back();
		}
	}
	vector<string> generateParenthesis(int n) {
		string path;
		traceback(0, 0, n, path);
		return res;
	}
};
// @lc code=end

