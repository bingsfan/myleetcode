/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
public:
	int n;
	struct Dsu {
		vector<int> parent;
		Dsu(int n) {
			parent.resize(n + 1);
			for(int i = 0; i <= n; i++) {
				parent[i] = i;
			}
		}
		int find(int u) {
			if(parent[u] != u) {
				parent[u] = find(parent[u]);
			}
			return parent[u];
		}
		bool isSame(int u, int v) {
			u = find(u);
			v = find(v);
			return u == v;
		}
		void join(int u, int v) {
			u = find(u);
			v = find(v);
			if(u != v) {
				parent[v] = u;
			}
		}
	};
	bool isTreeAfterRemove(const vector<vector<int>> &edges, const vector<int> deleteEdge) {
		Dsu dsu(n);
		for(auto edge : edges) {
			if(edge == deleteEdge)
				continue;
			int u = edge[0], v = edge[1];
			if(dsu.isSame(u, v)) {
				return false;
			} else {
				dsu.join(u, v);
			}
		}
		return true;
	}
	vector<int> removeCircle(const vector<vector<int>> &edges) {
		Dsu dsu(n);
		int u, v;
		for(auto edge : edges) {
			u = edge[0], v = edge[1];
			if(dsu.isSame(u, v)) {
				break;
			} else {
				dsu.join(u, v);
			}
		}
		return { u, v };
	}
	vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
		n = edges.size();
		// 有n条边n个节点,先统计每条边的入度
		vector<int> indegree(n+1, 0);
		vector<vector<int>> res;
		for(auto edge : edges) {
			indegree[edge[1]]++;
		}
		for(auto edge : edges) {
			if(indegree[edge[1]] == 2) {
				res.push_back(edge);
			}
		}
		if(res.size() > 0) {
			// 如果大于零就一定有两条边，不过这两条边的顺序是正的，因此应该先删res[1]
			if(isTreeAfterRemove(edges, res[1])) {
				return res[1];
			} else {
				return res[0];
			}
		}
		// 只处理有环的,直接返回最后一条导致成环的就行了
		return removeCircle(edges);
	}
};
// @lc code=end
