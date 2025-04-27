/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	// 如果它是这一层队列中的最后一个元素，就加入res集合，用层序遍历，带quesize的
	vector<int> rightSideView(TreeNode *root) {
        if(root==nullptr) return {};
		queue<TreeNode *> que;
		vector<int> res;
		que.push(root);
		while(!que.empty()) {
			int qsize = que.size();
			for(int i = 0; i < qsize; i++) {
				TreeNode *top = que.front();
				que.pop();
				if(top->left)
					que.push(top->left);
				if(top->right)
					que.push(top->right);
				if(i == qsize - 1) {
					res.push_back(top->val);
				}
			}
		}
		return res;
	}
};
// @lc code=end

