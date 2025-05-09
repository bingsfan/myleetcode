/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
	// hash法
	/* ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode *> uset;
		ListNode *p = head;
		while(p) {
			if(uset.count(p)) {
				return p;
			}
			uset.insert(p);
			p = p->next;
		}
		return nullptr;
	} */
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;
		// 快慢指针判断是否有环
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) {
				ListNode *p = head;
				ListNode *q = slow;
				while(p != q) {
					p = p->next;
					q = q->next;
				}
				return p;
			}
		}
		return nullptr;
	}
};
// @lc code=end

