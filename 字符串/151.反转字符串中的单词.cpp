/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
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
    void removeExtraSpace(string &s)
    {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] != ' ')
            {
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                while (fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }
    string reverseWords(string s)
    {
        string res(s);
        removeExtraSpace(res);
        reverseString(res, 0, res.size() - 1);
        int start = 0;
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == ' ')
            {
                reverseString(res, start, i - 1);
                start = i + 1;
            }
        }
        reverseString(res, start, res.size() - 1);
        return res;
    }
};
// @lc code=end
