/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector<list<int>> graph(numCourses);
		vector<int> indegree(numCourses, 0);
		// 用邻接表构建图，统计入度
		for(auto &edge : prerequisites) {
			int from = edge[1];
			int to	 = edge[0];
			graph[from].push_back(to);
			indegree[to]++;
		}
		vector<int> res;
		queue<int> que;
		for(int i = 0; i < numCourses; i++) {
			if(indegree[i] == 0) {
				que.push(i);
			}
		}
		while(!que.empty()) {
			int cur = que.front();
			res.push_back(cur);
			que.pop();
			// 将cur相连的边的入度-1，如果减后的入度为0就加入队列
			for(auto &to : graph[cur]) {
				indegree[to]--;
				if(indegree[to] == 0) {
					que.push(to);
				}
			}
		}
		return res.size() == numCourses;
	}
};
// @lc code=end

