/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
/*
    这题就是判断高度差是不是大于1，如果是直接就不平衡了
    直白的想法就是写一个int返回值的getheight，和那个求最大深度的一模一样
*/
#if 1
// 第一种写法，getheight计算的很多了,但我更喜欢这个代码，很清晰
int getHeight(TreeNode* root){
	if(root==nullptr){
		return 0;
	}
	return 1+max(getHeight(root->left),getHeight(root->right));
}
bool isBalanced(TreeNode* root) {
	if(!root){
		return true;
	}
    int leftHeight=getHeight(root->left);
    int rightHeight=getHeight(root->right);
    if(abs(leftHeight-rightHeight)>1){
    	return false;
    }
    // 如果根节点的左右子树平衡，再去递归对比根节点的左右子树是否平衡
    return isBalanced(root->left)&&isBalanced(root->right);
}
#endif
#if 0
    // 第二种写法，试试
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (left == -1)
        {
            return -1;
        }
        if (right == -1)
        {
            return -1;
        }
        if (abs(left - right) > 1)
        {
            return -1;
            // 用-1来表示在求高度的过程中已经就不平衡了
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        if (getHeight(root) == -1)
        {
            return false;
        }
        return true;
    }
#endif
};
// @lc code=end
