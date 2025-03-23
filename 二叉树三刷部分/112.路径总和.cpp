/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
		这题跟所有路径差不多，都是要后序遍历，我还是倾向于把根节点的值放外面处理，因为都要用到根节点的
		刚才那个题给了我一个提醒，定义全局变量有时候得污染，其实可以都放到参数列表里面
		这题就这样，跟回溯的题也很像把
		用一个带返回值的把，这函数的功能就是判断目前的路径的sum是否能加起来为target
		如果节点为空了，而且sum还不为target就false
		有返回值我不接我在做你妈呢
	*/
	bool traceback(TreeNode *root, int &sum, int targetSum)
	{
		if (!root->left && !root->right && sum != targetSum)
		{
			return false;
		}
		if (!root->left && !root->right && sum == targetSum)
		{
			return true;
		}
		// 这里还是要用if，不然值加不进去的
		if (root->left)
		{
			sum += root->left->val;
			if (traceback(root->left, sum, targetSum))
				return true;
			sum -= root->left->val;
		}
		if (root->right)
		{
			sum += root->right->val;
			if (traceback(root->right, sum, targetSum))
				return true;
			sum -= root->right->val;
		}
		// 这里才加完了，root的处理逻辑处理完了，后序看看sum,看个勾八，感觉直接return false了
		return false;
	}
	bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (root == nullptr)
		{
			return false;
		}
		return traceback(root, root->val, targetSum);
	}
};
// @lc code=end
