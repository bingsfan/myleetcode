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
		if(head == nullptr) {
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
		return umap[head];
	}
};
// @lc code=end

