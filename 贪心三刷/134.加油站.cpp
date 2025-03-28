/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
  public:
    /*
    如果存在解那就是唯一的
    首先gas的总量应该大于等于cost的总量
    其次每一躺gas的剩余量应该够这趟的cost
  */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start, res, totalres;
        start = res = totalres = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            res += gas[i] - cost[i];
            totalres += gas[i] - cost[i];
            if (res < 0)
            {
                res = 0;
                start = i + 1;
            }
        }
        if (totalres < 0)
        {
            return -1;
        }
        return start;
    }
};
// @lc code=end
