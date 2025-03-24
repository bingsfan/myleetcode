/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
  public:
  /* 
    切割问题其实就是组合问题，需要再想想
  */
    bool isHuiwen(string s, int l, int r)
    {
        int i = l, j = r;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void traceback5(string s, int startIndex, vector<string> &path, vector<vector<string>> &res)
    {
        if (startIndex >= s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isHuiwen(s, startIndex, i)) // 判断[startIndex,i]的子串是不是回文,是的话才加入path
            {
                string tmp = s.substr(startIndex, i - startIndex + 1);
                path.push_back(tmp);
            }else{
                continue;
            }
            traceback5(s, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> path;
        vector<vector<string>> res;
        traceback5(s, 0, path, res);
        return res;
    }
};
// @lc code=end
