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
		// 使用小顶堆，每次将当前k个链表的头结点放进去比较
		// 每次取出最小节点，然后把这个节点所在链表的下一个节点也放进去
		priority_queue<ListNode *, vector<ListNode *>, mycompare> pq;
		for(auto &node : lists) {
            if(node){
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

