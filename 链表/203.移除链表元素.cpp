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
/* 
    大部分链表操作的问题，都偏向于添加一个虚拟头结点，这样不用对头结点做额外处理
    所有原先head中的元素，加上虚拟头结点后都是同一类节点
*/
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dhead=new ListNode();
        dhead->next=head;
        ListNode *p=dhead;
        while(p->next){
            if(p->next->val==val){
                p->next=p->next->next;
            }else{
                p=p->next;
            }
        }
        return dhead->next;
    }
};
// @lc code=end

