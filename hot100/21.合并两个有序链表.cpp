/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
		ListNode *dhead = new ListNode(-1);
		ListNode *s		= dhead;
		ListNode *p		= list1;
		ListNode *q		= list2;
		while(p && q) {
			// !while里面改成s->next=p; p=p->next;if完了之后s=s->next;
			if(p->val <= q->val) {
				s->next = p;
				s		= p;
				p		= p->next;
			} else {
				s->next = q;
				s		= q;
				q		= q->next;
			}
		}
		if(p) {	   // 如果弄完p还有的话
			s->next = p;
		}
		if(q) {
			s->next = q;
		}
		return dhead->next;
	}
};
// @lc code=end

