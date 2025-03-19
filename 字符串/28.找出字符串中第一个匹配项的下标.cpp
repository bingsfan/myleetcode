/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
  public:
    void getNext(int *next, string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (s[j] != s[i] && j > 0)
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        vector<int> next(needle.size(), 0);
        getNext(next.data(), needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return i + 1 - needle.size();
            }
            
        }
        return -1;
    }
};
// @lc code=end
