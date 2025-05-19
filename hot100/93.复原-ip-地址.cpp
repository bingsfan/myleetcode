/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
	vector<string> res1;
	bool isValid(string s, int l, int r) {
		int len = r - l + 1;
		if(len > 3 || len < 1) {
			return false;
		}
		if(s[l] == '0' && l != r) {
			return false;
		}
		string tmp = s.substr(l, len);
		if(stoi(tmp) > 255) {
			return false;
		}
		return true;
	}
	void traceback93(string &s, int startIndex, int cnt) {
		if(cnt == 3) {
			if(isValid(s, startIndex, s.size() - 1))
				res1.push_back(s);
			return;
		}
		for(int i = startIndex; i < s.size(); i++) {
			if(isValid(s, startIndex, i)) {
				s.insert(s.begin() + i + 1, '.');
				cnt++;
				traceback93(s, i + 2, cnt);
				cnt--;
				s.erase(s.begin() + i + 1);
			}
		}
	}
	vector<string> restoreIpAddresses(string s) {
		traceback93(s, 0, 0);
		return res1;
	}
};
// @lc code=end

