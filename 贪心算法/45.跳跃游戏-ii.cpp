/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
/* 
    这题有点没想明白，还得看看
    要注意当前的最大边界和下一步的最大边界，当到达当前的最大边界了，直接要更新当前边界为下一步最大边界
    步数的问题：其实相当于从开始走到nowend->nextend
*/
class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int nowend = 0;
        int nextEnd = -1;
        if (nums.size() == 1)
        {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nextEnd = max(nextEnd, i + nums[i]);
            if (i == nowend)
            {
                nowend = nextEnd;
                step++;
                if(nowend>=nums.size()-1){
                    break;
                }
            }
            
        }
        return step;
    }
};
// @lc code=end
