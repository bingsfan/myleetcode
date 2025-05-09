/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
/* 
    先定义中止，nullptr，return 0；
    然后分情况，不用分了好像，直接猛猛遍历左右子树就行了
*/

    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
// @lc code=end

