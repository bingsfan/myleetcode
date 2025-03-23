/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
class Solution
{
public:
    #if 0
    /*
        我管你这那我看见二叉树怎么找，我直接就是迭代，不迭代我不爽m3？
    */
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val > val)
            {
                cur = cur->left;
            }
            else if (cur->val < val)
            {
                cur = cur->right;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }
    # endif
    /* 
        还是试试递归把
    */
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val>val){
            return searchBST(root->left,val);
        }else if(root->val<val){
            return searchBST(root->right,val);
        }else{
            return root;
        }
    }
};
// @lc code=end
