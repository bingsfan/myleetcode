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
	bool hasCycle(ListNode *head) {
		// 判断链表是否有环，要使用快慢指针，和找链表中点的过程很像
		ListNode *slow = head;
		ListNode *fast = head;
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

