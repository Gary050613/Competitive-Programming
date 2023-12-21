#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, K, nxt[MM], ans[MM];
bool vis[MM];
vector<int> g[MM];
set<int> st;
void dfs(int cur){
    if(vis[cur]){
        // ans[start].insert(ans[cur].begin(), ans[cur].end());
        return;
    }
    vis[cur] = 1;
    for(int j=0;j<g[cur].size();j++) st.insert(g[cur][j]);
    dfs(nxt[cur]);
}
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++) {nxt[i]=i; g[i].push_back(i);}
    for(int i=0, a, b;i<K;i++){
        cin >> a >> b;
        g[nxt[a]].push_back(b);
        g[nxt[b]].push_back(a);
        swap(nxt[a], nxt[b]);
    }
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        st.clear();
        // for(int j=0;j<g[i].size();j++) ans[i].insert(g[i][j]);
        dfs(i);
        ans[i]=st.size();
        int cur = nxt[i];
        while(cur!=i) {ans[cur]=st.size();cur=nxt[cur];}
    }
    for(int i=1;i<=N;i++) cout << ans[i] << endl;
    return 0;
}