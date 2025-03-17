/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
  int getLength(ListNode *l)
  {
      ListNode *p = l;
      int res = 0;
      while (p)
      {
          p = p->next;
          res++;
      }
      return res;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
      int lenA = getLength(headA);
      int lenB = getLength(headB);
      if (lenA < lenB)
      {
          swap(headA, headB);
          swap(lenA, lenB);
      }
      int k = lenA - lenB;
      ListNode *p = headA;
      ListNode *q = headB;
      while (k--)
      {
          p = p->next;
      }
      while (p && q)
      {
          if (p == q)
          {
              return p;
          }
          p = p->next;
          q = q->next;
      }
      return nullptr;
  }
};
// @lc code=end

