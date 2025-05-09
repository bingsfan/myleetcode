/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
	ListNode *swapPairs(ListNode *head) {
		// 要对头结点有操作，所以需要虚拟头结点
		ListNode *dhead = new ListNode(0);
		dhead->next		= head;
		ListNode *p		= dhead;
		while(p->next && p->next->next) {
			ListNode *q = p->next;
			ListNode *r = p->next->next;
			p->next		= r;
			q->next		= r->next;
			r->next		= q;
			p			= p->next->next;
		}
		return dhead->next;
	}
};
// @lc code=end

