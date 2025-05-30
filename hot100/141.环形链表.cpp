/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
	/* bool hasCycle(ListNode *head) {
        // 方法1：hash
		unordered_set<ListNode *> uset;
		ListNode *p = head;
		while(p) {
			if(uset.count(p)) {
				return true;
			} else {
				uset.insert(p);
			}
			p = p->next;
		}
		return false;
	} */
	bool hasCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) {
				return true;
			}
		}
		return false;
	}
};
// @lc code=end

