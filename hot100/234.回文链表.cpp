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
	ListNode *reverseList(ListNode *head) {
		ListNode *prev = nullptr;
		ListNode *p	   = head;
		while(p) {
			ListNode *tmp = p->next;
			p->next		  = prev;
			prev		  = p;
			p			  = tmp;
		}
		return prev;
	}
	bool isPalindrome(ListNode *head) {
		// 先找到中点，如果链表的长是奇数会直接找到中点，如果是偶数会找到靠后的中点
		ListNode *slow, *fast;
		slow = head, fast = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// slow就是中点或者靠后的中点
		ListNode *r = reverseList(slow);
		ListNode *l = head;
		while(r) {
			if(l->val != r->val) {
				return false;
			}
			l = l->next;
			r = r->next;
		}
		return true;
	}
};
// @lc code=end

