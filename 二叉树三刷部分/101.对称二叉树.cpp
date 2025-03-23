/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    求二叉树的属性，是后序
    因为要判断左子树和右子树是不是对称，然后才能知道整个树是不是对称二叉树
*/
    bool compare(TreeNode* t1,TreeNode* t2){
        if(!t1&&!t2){
            return true;
        }else if(!t1&&t2||!t2&&t1){
            return false;
        }
        // 这时候t1和t2都不为空了
        bool left;
        bool right;
        if(t1->val==t2->val){
            left=compare(t1->left,t2->right);
            right=compare(t1->right,t2->left);
        }else{
            return false;
        }
        return left && right;
    }
    bool isSymmetric(TreeNode* root) {
        return compare(root->left,root->right);
    }
};
// @lc code=end

