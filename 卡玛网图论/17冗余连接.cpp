#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> father(n+1,0);
/* 
    这是个无向图，情况很好分
    如果不在一个并查集中就可以加入
    如果在那就不能加入，直接输出并且return，因为在一个集合内还加就会出现环
*/
void init(){
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
}
int find(int u){
    if(u==father[u]){
        return u;
    }
    return father[u]=find(father[u]);
}
bool isSame(int u,int v ){
    u=find(u);
    v=find(v);
    return u==v;
}
// 将u->v加入
void join(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    father[u]=v;
}
int main(){
    int s,t;
    cin>>n;
    init();
    for(int i=0;i<n;i++){
        cin>>s>>t;
        if(isSame(s,t)){
            cout << s << " " << t << endl;
            return 0;
        } else {
            join(s, t);
        }
    }

}