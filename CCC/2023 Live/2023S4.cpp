#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2005;
int N, M, u, v, l, c, cur = 1, fa[MM];
ll ans;
vector<pair<int, pair<int, int>>> g[MM];
pair<pair<int, int>, pair<int, int>> e[MM];
int find(int u){
    if(fa[u] == u) return u;
    fa[u] = find(fa[u]);
    return fa[u];
}
int cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b){
    return a.first.first < b.first.first;
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++) fa[i] = i;
    for(int i=0;i<M;i++){
        cin >> u >> v >> l >> c;
        g[u].push_back({c, {v, l}});
        g[v].push_back({c, {u, l}});
        e[i] = {{c, l}, {u, v}};
    }
    sort(e, e+M, cmp);
    for(int i=0;i<M;i++){
        if(find(e[i].second.first)!=find(e[i].second.second)){
            ans += e[i].first.first;
            fa[find(e[i].second.first)] = find(e[i].second.second);
        }
    }
    cout << ans << endl;
    return 0;
}