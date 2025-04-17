#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void stringJieLong(){
    // 用bfs的原因是一旦找到endstr那就是最短路径
    int n;
    cin>>n;
    string beginStr,endStr;
    cin>>beginStr>>endStr;
    unordered_set<string> uset;
    string tmp;
    while (n--)
    {
        cin>>tmp;
        uset.insert(tmp);
    }
    queue<string> que;
    que.push(beginStr);
    unordered_map<string,int> visited;//记录哪个字符串被访问过，并且记录到起点的距离
    int distance = 0;
    visited[beginStr]=0;
    while (!que.empty())
    {
        string oldStr = que.front();
        distance=visited[oldStr];
        que.pop();
        // 找在字典即uset里面和oldStr能连起来的,替换oldStr中的任意一个字符，如果替换完的new在字典中出现，那么可以加入队列
        for(int i=0;i<oldStr.size();i++){
            string newStr(oldStr);
            for(int j=0;j<26;j++){
                newStr[i]='a'+j;
                if(newStr==endStr){
                    cout<<distance+2<<endl;
                    return;
                }
                if(uset.count(newStr)&&!visited.count(newStr)){
                    visited[newStr]=distance+1;
                    que.push(newStr);
                }
            } 
        }
        
    }
    cout<<0<<endl;
}
int main(){
	stringJieLong();
	return 0;
}