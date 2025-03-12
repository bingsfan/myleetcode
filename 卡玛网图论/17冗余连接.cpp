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