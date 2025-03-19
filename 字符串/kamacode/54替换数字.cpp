#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
/*
输入：一个字符串 s,s 仅包含小写字母和数字字符。
输出：打印一个新的字符串，其中每个数字字符都被替换为了number
样例输入：a1b2c3
样例输出：anumberbnumbercnumber
数据范围：1 <= s.length < 10000。
*/
    string s;
    while (cin>>s)
    {
        int number_cnt=0;
        for(auto c:s){
            if(c>='1'&&c<='9'){
                number_cnt++;
            }
        }
        int oldIndex=s.size()-1;
        s.resize(s.size()+number_cnt*5);
        int newIndex = s.size() - 1;
        for(int i=oldIndex;i>=0;i--){
            if (s[i] >= '1' && s[i] <= '9'){
                s[newIndex--]='r';
                s[newIndex--]='e';
                s[newIndex--]='b';
                s[newIndex--]='m';
                s[newIndex--]='u';
                s[newIndex--]='n';
            }else{
                s[newIndex--]=s[i];
            }
        }
        cout<<s<<endl;
    }
}
