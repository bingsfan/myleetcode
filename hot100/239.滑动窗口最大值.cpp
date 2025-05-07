/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
	// 要保证是一个单调递减的特性
	struct myQueue {
		deque<int> q;
		void push(int k) {
			while(!q.empty() && k > q.back()) {
				q.pop_back();
			}
			q.push_back(k);
		}
		void pop(int k) {
			if(!q.empty() && k == q.front()) {
				q.pop_front();
			}
		}
		int front() {
			return q.front();
		}
	};
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		int n = nums.size();
		vector<int> res;
		myQueue q;
		for(int i = 0; i < k; i++) {
			q.push(nums[i]);
		}
		res.push_back(q.front());
		for(int i = k; i < n; i++) {
			q.pop(nums[i - k]);
			q.push(nums[i]);
			res.push_back(q.front());
		}
		return res;
	}
};
// @lc code=end