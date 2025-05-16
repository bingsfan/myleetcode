/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void traceback216(int n, int k, int startIndex, int sum) {
		if(path.size() == k) {
			if(sum == n) {
				res.push_back(path);
			}
			return;
		}
		for(int i = startIndex; 10 - i + path.size() >= k && sum + i <= n; i++) {
			path.push_back(i);
			sum += i;
			traceback216(n, k, i + 1, sum);
			sum -= i;
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		traceback216(n, k, 1, 0);
		return res;
	}
};
// @lc code=end

