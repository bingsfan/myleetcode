/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
  public:
    /*
        这题主要是弄清用来遍历数组的i，nowend,nextend的关系
        nums的长度大于等于1，肯定会至少走一步的，我不防先写出这一步的结果
        不对这个思路不对,首先原来写的代码少了如果数组长度为1，立刻返回0，因为压根就不用走一步。我自己写的还忽略的一种情况
        就是第一步就可以到达终点的情况，这个代码也就是标准答案更加简介点
        我在每一步跳跃的时候都要找到下次跳跃能跑到的最大值，所以需要遍历到这次跳跃的终点，将这一段遍历完才能找到最大的
    */
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        int nowend = 0;
        int nextend = -1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nextend = max(nextend, i + nums[i]);
            if (i == nowend)
            {
                nowend = nextend;
                res++;
                if (nextend >= nums.size() - 1)
                {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
