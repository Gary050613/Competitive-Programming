#include <bits/stdc++.h>
using namespace std;
int K, N, M, cow[105], cnt[1005], ans;
bool vis[1005];
vector<int> g[10005];
void dfs(int u){
    if(vis[u]) return;
    cnt[u]++;
    vis[u]=1;
    for(int i=0;i<g[u].size();i++) dfs(g[u][i]);
}
int main(){
    cin >> K >> N >> M;
    for(int i=0;i<K;i++){
        cin >> cow[i];
    }
    for(int i=0, a, b;i<M;i++){
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i=0;i<K;i++){
        memset(vis, 0, sizeof(vis));
        dfs(cow[i]);
    }
    for(int i=1;i<=N;i++) if(cnt[i]==K) ans++;
    cout << ans << endl;
    return 0;
}