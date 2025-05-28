/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		typedef pair<int, int> pli;
		struct mycompare2 {
			bool operator()(const pli &a, const pli &b) {
				return a.second > b.second;
			};
		};

		unordered_map<int, int> umap;
		for(auto &num : nums) {
			umap[num]++;
		}
		vector<int> res;
		priority_queue<pli, vector<pli>, mycompare2> pq;
		for(auto it = umap.begin(); it != umap.end(); it++) {
			pq.emplace(*it);
			if(pq.size() > k) {
				pq.pop();
			}
		}
		while(!pq.empty()) {
			res.push_back(pq.top().first);
			pq.pop();
		}
		return res;
	}
};
// @lc code=end

