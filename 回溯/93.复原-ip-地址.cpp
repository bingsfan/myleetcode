/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
  public:
  /* 
    这题两中写法，这种效率高，但是理解稍微麻烦一点点
    另一种就是我参数里面再加一个path，满足条件后再加入到res里面，多出来了空间浪费
  */
    bool isValid(string s, int start, int end)
    {
        // 检查子串长度是否合法
        int len = end - start + 1;
        if (len > 3 || len < 1)
            return false;
        // s仅由数字组成
        if (s[start] == '0' && start != end)
        {
            return false;
        }
        string tmp = s.substr(start, end - start + 1);
        if (stoi(tmp) > 255)
        {
            return false;
        }
        return true;
    }
    void traceback6(string &s, int startIndex, int cnt, vector<string> &res)
    {
        if (cnt == 3)
        {
            if (isValid(s, startIndex, s.size() - 1))
            {
                res.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            // 依旧是[startIndex,i]这个区间，要判断这一段子串合不合理,合理才进去执行
            if (isValid(s, startIndex, i))
            {
                string tmp = s.substr(startIndex, i - startIndex + 1);
                // 如果不用path，直接修改s
                // cnt++;
                s.insert(s.begin() + i + 1, '.');
                traceback6(s, i + 2, cnt+1, res);
                // cnt--;
                s.erase(s.begin() + i + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        string path;
        vector<string> res;
        traceback6(s, 0, 0, res);
        return res;
    }
};
// @lc code=end
