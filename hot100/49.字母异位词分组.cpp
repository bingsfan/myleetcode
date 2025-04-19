/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		int n = strs.size();
		// 异位词经过排序之后应该是相同的,排序前的key作为键，值是排序后的字符串
		unordered_map<string, vector<string>> umap;
		vector<vector<string>> res;
		for(auto &str : strs) {
			string key = str;
			sort(str.begin(), str.end());
			umap[str].push_back(key);
		}
		// 遍历map
		for(auto &path : umap) {
			res.push_back(path.second);
		}
		return res;
	}
};
// @lc code=end

