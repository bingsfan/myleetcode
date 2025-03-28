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
    转成字符串解决，遍历需要从后往前遍历
    如果x>y，x-1，y及其之后的数都变成9，不能从后向前遍历
    用一个位置记录y在那儿，y是要找的第一个x>y的位置
  */
    int monotoneIncreasingDigits(int n)
    {
        string str = to_string(n);
        int start = str.size(); // 如果start没有赋值，就不会进入下一个循环，给赋值9的过程了
        for (int i = str.size() - 1; i > 0; i--)
        {
            if (str[i - 1] > str[i])
            {
                str[i - 1] -= 1;
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
