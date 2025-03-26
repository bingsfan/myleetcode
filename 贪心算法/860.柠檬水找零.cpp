/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
  public:
    bool lemonadeChange(vector<int> &bills)
    {
        int cnt5, cnt10, cnt20;
        cnt10 = cnt5 = cnt20 = 0;
        for (auto money : bills)
        {
            if (money == 5)
            {
                cnt5++;
            }
            else if (money == 10)
            {
                if (cnt5 > 0)
                {
                    cnt5--;
                    cnt10++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (cnt5 >= 1 && cnt10 >= 1)
                {
                    cnt5--;
                    cnt10--;
                }
                else if (cnt5 >= 3)
                {
                    cnt5 -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
