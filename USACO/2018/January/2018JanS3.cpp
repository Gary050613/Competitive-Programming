#include <bits/stdc++.h>
using namespace std;

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

typedef pair<int, int> pii;
const int MM = 5005;
int N, Q, p, q, r, k, v;
bool visited[MM];
vector<pii> g[MM];

int dfs(int u){
    //cout << u<<endl;
    int ans=0;
    visited[u]=1;
    for(int i=0;i<g[u].size();i++){
        if(!visited[g[u][i].first]&&g[u][i].second>=k){
            ans += dfs(g[u][i].first)+1;
        }
    }
    return ans;
}
int main(){
    setIO("mootube");
    cin >> N >> Q;
    for(int i=0;i<N-1;i++){
        cin >> p >> q >> r;
        g[p].push_back({q, r});
        g[q].push_back({p, r});
    }
    while(Q--){
        cin >> k >> v;
        //cout << "starting at "<<v << " with k "<<k << endl;
        memset(visited, 0, sizeof(visited));
        cout << dfs(v) << endl;
    }
    return 0;
}