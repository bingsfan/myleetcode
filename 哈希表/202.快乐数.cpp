/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
    /* 
    对取余和除的这个求和过程还有一些不熟悉
    */
  public:
    int getsum(int n)
    {
        int sum = 0;
        int k;
        while (n)
        {
            k = n % 10;
            n = n / 10;
            sum += k * k;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> uset;
        while (1)
        {
            int sum = getsum(n);
            if (sum == 1)
            {
                return true;
            }
            else if (uset.count(sum))
            {
                return false;
            }
            else if (!uset.count(sum))
            {
                uset.insert(sum);
            }
            n = sum;
        }
    }
};
// @lc code=end
