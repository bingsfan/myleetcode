/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    依旧是后序，为什么呢？
    都为空可以注释，因为left和right都为0，所以最后还是1
*/
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left&&!root->right){
            return 1+minDepth(root->left);
        }else if(!root->left&&root->right){
            return 1+minDepth(root->right);
        }
        // else if(!root->left&&!root->right){
        //     return 1;
        // }
        // 下面处理都不为空的情况
        int left = minDepth(root->left);
        int right=minDepth(root->right);
        return 1+min(left,right);
    }
};
// @lc code=end

