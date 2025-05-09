/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
/* 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode *> uset;
		ListNode *pa = headA;
		ListNode *pb = headB;
		while(pa) {
			uset.insert(pa);
			pa = pa->next;
		}
		while(pb) {
			if(uset.count(pb)) {
				return pb;
			}
			pb = pb->next;
		}
		return nullptr;
	} */
	// 双指针解法
	int getLength(ListNode *head) {
		int len = 0;
		while(head) {
			head = head->next;
			len++;
		}
		return len;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lena = getLength(headA);
		int lenb = getLength(headB);
		if(lenb > lena) {
			swap(lena, lenb);
			swap(headA, headB);
		}
		int k		 = lena - lenb;
		ListNode *pa = headA;
		ListNode *pb = headB;
		while(k--) {
			pa = pa->next;
		}
		while(pa) {
			if(pa == pb) {
				return pa;
			}
			pa = pa->next;
			pb = pb->next;
		}
		return nullptr;
	}
};
// @lc code=end

