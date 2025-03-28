/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
  public:
    /*
    用一个数组来映射每一个字母出现的最远位置
    如果当前字母已经到了最远位置，就把这个加入res数组中（不太对）
    不是当前字母，而是这几个字母最远位置的最大值，要分段做，
    定义一个start和end，一边遍历一边找end的最大值，不断更新end，直到已经找到某一段的最大值
    index代表s[i]在数组中的位置，做了一个映射
  */
    vector<int> partitionLabels(string s)
    {
        vector<int> hash(26, 0);
        int index;
        for (int i = 0; i < s.size(); i++)
        {
            index = s[i] - 'a';
            hash[index] = i;
        }
        vector<int> res;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            index = s[i] - 'a';
            end = max(end, hash[index]);
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end
