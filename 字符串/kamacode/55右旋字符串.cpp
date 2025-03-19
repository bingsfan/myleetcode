#include <iostream>
using namespace std;

void reverseString(string &s,int start,int end)
{
    int left=start;
    int right=end;
    while (left<=right)
    {
        swap(s[left],s[right]);
        left++;
        right--;
    }
}
int main(int argc, char *argv[])
{
/* 
输入描述
输入共包含两行，第一行为一个正整数 k，代表右旋转的位数。第二行为字符串 s，代表需要旋转的字符串。
输出描述
输出共一行，为进行了右旋转操作后的字符串。
输入示例
2
abcdefg
输出示例
fgabcde 
*/
    int k;
    string s;
    cin>>k;
    cin>>s;
    reverseString(s,0,s.size()-1);
    reverseString(s,0,k-1);
    reverseString(s, k, s.size() - 1);
    cout<<s<<endl;
}