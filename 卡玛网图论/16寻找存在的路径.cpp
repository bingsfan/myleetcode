#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> father(n+1,0);

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
// 将v->u加入
void join(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    father[u]=v;
}
int main(){
    int m,s,t,start,end;
    cin>>n>>m;
    init();
    while(m--){
        cin>>s>>t;
        join(s,t);
    }
    cin>>start>>end;
    if(isSame(start,end)){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}