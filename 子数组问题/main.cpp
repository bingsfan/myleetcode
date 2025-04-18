#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
	unordered_set<char> uset;
	int left   = 0;
	int maxlen = 0;
	for(int right = 0; right < s.size(); right++) {
		// 如果当前字符已经存在，移动左边界直到没有重复为止
		while(uset.count(s[right])) {
			uset.erase(s[left]);
			left++;
		}
		uset.insert(s[right]);
		maxlen = max(maxlen, right - left + 1);
	}
	return maxlen;
}
int maxSubArray(vector<int> &nums) {
	int maxSum = nums[0];
	int curSum = nums[0];
	for(int right = 1; right < nums.size(); right++) {
		// 如果当前窗口和为负，重置当前窗口，从当前元素重新开始
		if(curSum < 0) {
			curSum = nums[right];
		} else {
			curSum += nums[right];
		}
		maxSum = max(maxSum, curSum);
	}
	return maxSum;
}
int findLengthOfLCIS(vector<int> &nums) {
	int left = 0;
	int res	 = 1;
	for(int right = 1; right < nums.size(); right++) {
		if(nums[right] > nums[right - 1]) {
			// 啥也不干就行了
		} else {
			left = right;
		}
        res = max(res, right - left + 1);
	}
	return res;
}
int extend(string s,int i,int j,int n){
    int res = 0;
    while (i>=0&&j<n&&s[i]==s[j])
    {
        i--,j++;
        res++;
    }
    return res;
}
int countSubstrings(string s) {
    int res = 0;
    int n = s.size();
    for(int i=0;i<s.size();i++){
        res += extend(s,i,i,n);
        res += extend(s,i,i+1,n);
    }
    return res;
}
string findMax(string s, int i, int j, int n) {
	while (i >= 0 && j < n && s[i] == s[j]) {
		i--, j++;
	}
	return s.substr(i+1, j - i - 1);
}
// 还有高手，求出最长的回文子串
string longestPalindrome(string s) {
	int maxlen = 1;
	string res1;
	string res2;
	string res;
	res = s[0];
	int n = s.size();
	for (int i = 0; i < s.size(); i++) {
		res1 = findMax(s, i, i, n);
		res2 = findMax(s, i, i + 1, n);
		if (res1.size() > res.size())
			res = res1;
		if (res2.size() > res.size())
			res = res2;
	}
	return res;
}
int main(int argc, char *argv[]) {
	string res = longestPalindrome("cbbd");
	cout<<res<<endl;
	return 0;
}
