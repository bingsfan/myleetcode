/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
  public:
    /*
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合
    如何映射一到多？一个char要映射三四个字母，用一个二维数组
  */
    vector<string> letterMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void traceback2(int index, string digits, string &path, vector<string> &res)
    {
        if (path.size() == digits.size())
        {
            res.push_back(path);
            return;
        }
        string letters = letterMap[digits[index] - '0'];
        for (char c : letters)
        {
            path.push_back(c);
            traceback2(index + 1, digits, path, res);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        string path;
        vector<string> res;
        if(digits.empty()){
            return res;
        }
        traceback2(0, digits, path, res);
        return res;
    }
};
// @lc code=end
