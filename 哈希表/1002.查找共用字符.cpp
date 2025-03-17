/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution
{
  public:
    /*
    先统计第一个字符串的hash数组，然后之后每一个字符串和第一个的做比较
    先取最小的,最后得到的就是所有都有的最小个数
    然后将hash中不等于0的结果弄成字符串，弄到字符串数组res中
  */
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> table0(26, 0);
        vector<string> res;
        for (auto s : words[0])
        {
            table0[s - 'a']++;
        }
        vector<int> other(26, 0);
        for (int i = 1; i < words.size(); i++)
        {
            vector<int> other(26, 0);
            for (auto s : words[i])
            {
                other[s - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                table0[i] = min(table0[i], other[i]);
            }
        }
        for (int i = 0; i < 26; i++)
        {
            while (table0[i] != 0)
            {
                string s(1, i + 'a');
                res.push_back(s);
                table0[i]--;
            }
        }
        return res;
    }
};
// @lc code=end
