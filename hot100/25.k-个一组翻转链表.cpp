/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if(k == 1) {
			return head;
		}
		ListNode *dhead = new ListNode(0);
		dhead->next		= head;
		ListNode *pre	= dhead;
		ListNode *end	= dhead;
		while(1) {
			for(int i = 0; i < k && end != nullptr; i++) {
				end = end->next;
			}
			if(end == nullptr) {
				break;
			}
			// 开始反转
			ListNode *start = pre->next;
			ListNode *next	= end->next;
			end->next		= nullptr;
			pre->next		= reverseList(start);
			start->next		= next;
			pre				= start;
			end				= start;
		}
		return dhead->next;
	}
};
// @lc code=end

