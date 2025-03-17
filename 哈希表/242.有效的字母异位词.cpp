/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词
输入: s = "anagram", t = "nagaram"
输出: true
*/
// @lc code=start
class Solution {
public:
/* 
    想叉了，一上来就想用map<char,int> char字符在字符串中出现的次数
    这就要用两个map，用来比较两个map是不是一样，每个字符出现的次数都一样，不太会遍历
    对于这种比较字母的直接用一个数组就行了
*/
  bool isAnagram(string s, string t)
  {
      vector<int> table(26, 0);
      for (auto c : s)
      {
          table[c - 'a']++;
      }
      for (auto c : t)
      {
          table[c - 'a']--;
      }
      for (auto num : table)
      {
          if (num != 0)
          {
              return false;
          }
      }
      return true;
  }
};
// @lc code=end

