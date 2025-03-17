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
  /*
      fast和slow得先移动再判断是否相等，之前直接判断相等再移动fast和slow写的有问题了
      while的循环条件也有问题，之前写的fast->next->next且slow->next
      其实要访问next只要fast就行
      这个解法不太好想，不如直接哈希法解决
  */
  ListNode *detectCycle(ListNode *head)
  {
      ListNode *fast = head;
      ListNode *slow = head;
      while (fast && fast->next)
      {
          fast = fast->next->next;
          slow = slow->next;
          if (fast == slow)
          {
              ListNode *p1 = head;
              ListNode *p2 = fast;
              while (p1 != p2)
              {
                  p1 = p1->next;
                  p2 = p2->next;
              }
              return p1;
          }
      }
      return nullptr;
  }
};
// @lc code=end

