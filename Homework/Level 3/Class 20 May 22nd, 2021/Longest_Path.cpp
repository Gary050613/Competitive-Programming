#include <bits/stdc++.h>
using namespace std;
int n, m, in[100005], dp[100005], ans=0; vector<int> adj[1000005]; queue<int> q;
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); in[v]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0) {q.push(i); dp[i]=0;}
    }
    while(!q.empty()){
        int u = q.front(); q.pop(); ans = max(ans, dp[u]);
        for(int v:adj[u]){
            dp[v] = max(dp[v], dp[u]+1);
            if(--in[v]==0) q.push(v);
        }
    }
    cout << ans << endl;
    return 0;
}