#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, ans=0;
bool v[MM];
vector<int> g[MM];
void dfs(int u){
    if(v[u]) return;
    int edges=0, cur=1;
    v[u]=1;
    if(u==1) edges=1;
    edges+=g[u].size()-1;
    while(cur<edges+1){
        cur*=2;
        ans++;
    }
    for(int i=0;i<g[u].size();i++){
        if(!v[g[u][i]]) {dfs(g[u][i]);ans++;}
    }
}
int main(){
    cin >> N;
    for(int i=0, u, v;i<N-1;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
