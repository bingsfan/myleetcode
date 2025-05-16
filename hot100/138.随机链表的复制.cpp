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
		// 方法1 使用hash存储
/* 		if(head == nullptr) {
			return nullptr;
		}
		unordered_map<Node *, Node *> umap;
		Node *cur = head;
		while(cur) {
			umap[cur] = new Node(cur->val);
			cur		  = cur->next;
		}
		for(auto &[r, c] : umap) {
			if(r->next != nullptr) {
				c->next = umap[r->next];
			}
			if(r->random != nullptr) {
				c->random = umap[r->random];
			}
		}
		return umap[head]; */
		// !方法2：原地复制
		if(head == nullptr) {
			return nullptr;
		}
		// 在原来的链表后面复制一个新节点,这里相当于把val和next属性添加了
		Node *cur = head;
		while(cur) {
			Node *copy = new Node(cur->val);
			copy->next = cur->next;
			cur->next  = copy;
			cur		   = cur->next->next;
		}
		// 现在开始复制random属性
		cur = head;
		while(cur) {
			Node *copy = cur->next;
			if(cur->random) {
				copy->random = cur->random->next;
			}
			cur = copy->next;
		}
		// 将原链表和新链表拆开
		Node *dhead	   = new Node(0);
		Node *copyNode = dhead;
		cur			   = head;
		while(cur) {
			Node *copy	   = cur->next;
			copyNode->next = copy;
			copyNode	   = copyNode->next;
			cur->next	   = copy->next;
			cur			   = cur->next;
		}
		return dhead->next;
	}
};
// @lc code=end

