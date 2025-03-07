// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head->next){
            return head;
        }
        ListNode *p = head;
        while(p->next){
            if(p->next->val==val){
                ListNode *q = p->next;
                p->next = q->next;
                delete q;
            }else{
                p=p->next;
            }
        }
        if(head->val == val){
            ListNode *p = head->next;
            delete head;
            return p;
        }
        return head;
    }
};
// @lc code=end

