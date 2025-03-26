/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
  public:
//   这题二刷还是有点问题
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int size = gas.size();
        int start = 0;
        int rest=0;
        int totalRest = 0;
        for (int i = 0; i < size; i++)
        {
            rest += gas[i] - cost[i];
            totalRest += gas[i] - cost[i];
            if (rest < 0)
            {
                start = i + 1;
                rest = 0;
            }
        }
        if (totalRest < 0)
        {
            return -1;
        }
        return start;
    }
};
// @lc code=end
