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
		ListNode *dhead = new ListNode(0);
		ListNode *tail	= dhead;
		ListNode *l1	= list1;
		ListNode *l2	= list2;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				tail->next = l1;
				l1		   = l1->next;
			} else {
				tail->next = l2;
				l2		   = l2->next;
			}
			tail = tail->next;
		}
		if(l1) {
			tail->next = l1;
		}
		if(l2) {
			tail->next = l2;
		}
		return dhead->next;
	}
};
// @lc code=end

