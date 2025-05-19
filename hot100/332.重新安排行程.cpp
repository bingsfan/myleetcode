/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
	vector<string> findItinerary(vector<vector<string>> &tickets) {
		unordered_map<string, map<string, int>> tickets_map;
		for(auto &ticket : tickets) {
			tickets_map[ticket[0]][ticket[1]]++;
		}
		vector<string> res;
		function<void(const string &)> dfs = [&](const string &from) {
			for(auto &[to, count] : tickets_map[from]) {
				if(count > 0) {
					count--;
					dfs(to);
				}
			}
			res.push_back(from);
		};
		dfs("JFK");
		reverse(res.begin(), res.end());
		return res;
	}
};
// @lc code=end

