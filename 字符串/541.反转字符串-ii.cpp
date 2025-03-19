/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
  public:
    void reverseString(string &s, int start, int end)
    {
        int left = start;
        int right = end;
        while (left <= right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    /*
    给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

    如果剩余字符少于 k 个，则将剩余字符全部反转。
    如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

    */
    string reverseStr(string s, int k)
    {
        string res(s);
        int times = res.size() / (2 * k);
        int left = res.size() % (2 * k);
        int p = 0;
        // 处理前面能凑成2*k这段的
        while (times--)
        {
            reverseString(res, p, p + k-1);
            p += k * 2;
        }
        // 处理剩下的
        if (left < k)
        {
            reverseString(res, p, s.size() - 1);
        }
        else
        {
            reverseString(res, p, p + k-1);
        }
        return res;
    }
};
// @lc code=end
