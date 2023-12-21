#include <bits/stdc++.h>
using namespace std;
const int MM = 205;
int N, ans=0, x[MM], y[MM], r[MM];
bool visited[MM]={0};
vector<int> g[MM];
int dfs(int u){
    // if(visited[u]) return;
    // visited[u]=1;
    // ans=max(ans, w);
    int a=0;
    for(int i = 0;i<g[u].size();i++){
        if(visited[g[u][i]]) continue;
        visited[g[u][i]]=1;
        a+=1+dfs(g[u][i]);
    }
    return a;
    // visited[u]=0;
}
int main(){
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> x[i] >> y[i] >> r[i];
        for(int j = 0;j<i;j++){
            // x[j] y[j]  --   x[i] y[i]
            if(abs(x[j]-x[i])*abs(x[j]-x[i]) + abs(y[j]-y[i])*abs(y[j]-y[i]) <= r[j]*r[j]){
                g[j].push_back(i);
            }
            if(abs(x[j]-x[i])*abs(x[j]-x[i]) + abs(y[j]-y[i])*abs(y[j]-y[i]) <= r[i]*r[i]){
                g[i].push_back(j);
            }
        }
    }
    // for(int i = 0;i<N;i++){
    //     cout << "Head " << i << " : ";
    //     for(int j = 0;j<g[i].size();j++) cout << g[i][j] << " ";
    //     cout << endl;
    // }
    for(int i = 0;i<N;i++) {memset(visited, 0, sizeof(visited));visited[i]=1; ans=max(ans,1+dfs(i));}
    cout << ans << endl;
    return 0;
}