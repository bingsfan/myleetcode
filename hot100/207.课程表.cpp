/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
	/*
		拓扑排序像是，靠这种依赖关系的，但是这个测试用例给的太恶心了，我本身想用一个并查集判断，感觉就是判断有没有环，先试试把
		并查集通过44/54，一个有环的就不行了，实际上就是拓扑，从后往前的边，先统计入度，如果入度为0，加入队列
		然后将该节点出队列，加入一个结果数组中去，最后判断这个结果数组的长度是否和边数相等
		出队列后，所有与之相连的点入度都要-1，如果==0了，继续加入，直到加入不下去
	*/
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector<int> indegree(numCourses, 0);
		for(auto &vec : prerequisites) {
			indegree[vec[0]]++;
		}
		queue<int> que;
		for(int i = 0; i < numCourses; i++) {
			if(indegree[i] == 0) {
				que.push(i);
			}
		}
		vector<int> res;
		while(!que.empty()) {
			int cur = que.front();
			que.pop();
			res.push_back(cur);
			for(auto &vec : prerequisites) {
				if(vec[1] == cur) {
					indegree[vec[0]]--;
					if(indegree[vec[0]] == 0) {
						que.push(vec[0]);
					}
				}
			}
		}
		return res.size() == numCourses;
	}
};
// @lc code=end

