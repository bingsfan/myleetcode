/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
/* 
    使用头插法将原先链表中的一个个节点都插入新的dhead后
*/
    ListNode* reverseList(ListNode* head) {
        ListNode *dhead = new ListNode();
        ListNode *p = head;
        while (p)
        {
            ListNode *tmp = new ListNode(p->val);
            tmp->next = dhead->next;
            dhead->next = tmp;
            p = p->next;
        }
        return dhead->next;
    }
};
// @lc code=end

