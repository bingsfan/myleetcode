/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 * 给你两个字符串：ransomNote 和 magazine ,判断 ransomNote 能不能由 magazine 里面的字符构成。
 */

// @lc code=start
class Solution
{
  public:
    /*
    字符串的肯定直接用数组来当容器，直接遍历magazine，将里面出现的加入
  */
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> hash(26, 0);
        for (auto s : magazine)
        {
            hash[s - 'a']++;
        }
        for (auto s : ransomNote)
        {
            hash[s - 'a']--;
        }
        for (auto i : hash)
        {
            if (i < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
