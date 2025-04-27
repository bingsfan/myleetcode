/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
	bool isPalindrome(ListNode *head) {
		// 用快慢指针找中间节点，然后反转对比，最后将链表恢复原状
		if(!head || !head->next) {
			return true;
		}
		// 找中点
		ListNode *slow = head;
		ListNode *fast = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// 翻转后半段链表
		ListNode *prev = nullptr;
		while(slow) {
			ListNode *tmp = slow->next;
			slow->next	  = prev;
			prev		  = slow;
			slow		  = tmp;
		}
		ListNode *left	= head;
		ListNode *right = prev;
		while(right) {
			if(left->val != right->val) {
				return false;
			}
			left  = left->next;
			right = right->next;
		}
		return true;
	}
};
// @lc code=end

