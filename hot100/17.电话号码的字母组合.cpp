/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
	vector<string> letterMap = { "",	"",	   "abc",  "def", "ghi",
								 "jkl", "mno", "pqrs", "tuv", "wxyz" };
	string path1;
	vector<string> res1;
	void traceback17(string &digits, int startIndex) {
		if(path1.size() == digits.size()) {
			res1.push_back(path1);
			return;
		}
		string letters = letterMap[digits[startIndex] - '0'];
		for(auto &c : letters) {
			path1.push_back(c);
			traceback17(digits, startIndex + 1);
			path1.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		if(digits.empty()) {
			return res1;
		}
		traceback17(digits, 0);
		return res1;
	}
};
// @lc code=end

