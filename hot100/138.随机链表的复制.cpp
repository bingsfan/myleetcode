/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node *copyRandomList(Node *head) {
        // 这个代码还没有编程自己的
		if(head == nullptr) {
			return head;
		}
		unordered_map<Node *, Node *> map;
		Node *cur = head;
		// 第一次遍历记录值
		while(cur) {
			map[cur] = new Node(cur->val);
			cur		 = cur->next;
		}
		// 第二次遍历记录next和random关系
		cur = head;
		while(cur) {
			map[cur]->next	 = map[cur->next];
			map[cur]->random = map[cur->random];
			cur				 = cur->next;
		}
		// 也可以这样写
		//  !第二次遍历：连接 next 和 random
		for(auto &[r, c] : map) {
			c->next	  = map[r->next];
			c->random = map[r->random];
		}
		return map[head];
	}
};
// @lc code=end

