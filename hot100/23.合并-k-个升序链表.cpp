/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	struct mycompare {
		bool operator()(ListNode *a, ListNode *b) {
			return a->val > b->val;
		}
	};

	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode *, vector<ListNode *>, mycompare> pq;
		int k = lists.size();
		for(auto &node : lists) {
			if(node) {
				pq.push(node);
			}
		}
		ListNode dhead(0);
		ListNode *tail = &dhead;
		while(!pq.empty()) {
			ListNode *node = pq.top();
			pq.pop();
			tail->next = node;
			tail	   = tail->next;
			if(node->next) {
				pq.push(node->next);
			}
		}
		return dhead.next;
	}
};
// @lc code=end

