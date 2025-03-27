/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
  public:
    /*
      核心思路：当str[i-1]>str[i]的时候，str[i-1]--,str[i]变成9
      遍历需要从后往前，从前往后模拟一下会发现不太行
      自己写的函数对于输入为100解决的时候报错了
      正确的处理方式应该是，每次找到一个递减的位置，i-1还是应该--，str[i]是之后的位置都要放9，用一个变量来记录，
      记录完了一次性处理
  */
    int monotoneIncreasingDigits(int n)
    {
        string str = to_string(n);
        int start = str.size();
        for (int i = str.size() - 1; i > 0; i--)
        {
            if (str[i - 1] > str[i])
            {
                str[i - 1]--;
                start = i;
            }
        }
        for (int i = start; i < str.size(); i++)
        {
            str[i] = '9';
        }
        return stoi(str);
    }
};
// @lc code=end
