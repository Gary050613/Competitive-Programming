// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5+5;
int N, M, T[MM], ent[MM], ext[MM], fa[MM], cnt=1, dep[MM];
bool v[MM], ans[MM];
vector<int> g[MM], ord;
stack<int> stk[MM];
vector<pair<int, pi> > q[MM];
void dfs(int a){
    ent[a]=cnt++;
    for(int i=0;i<g[a].size();i++){
        if(!v[g[a][i]]){
            v[g[a][i]]=1;
            // fa[g[a][i]]=a;
            dep[g[a][i]]=dep[a]+1;
            dfs(g[a][i]);
        }
    }
    ext[a]=cnt-1;
}
void dfs2(int a){
    stk[T[a]].push(a); ord.push_back(a);
    for(int i=0;i<q[a].size();i++){
        int C = q[a][i].second.second;
        if(!stk[C].empty()){
            int V = stk[C].top();
            if(V == a) ans[a]=1;
            else{
                V = ord[dep[V]+1];
                int B = q[a][i].second.first;
                if(!(ent[V]<ent[B]&&ext[V]>=ext[B])) ans[q[a][i].first] = 1;
            }
        }
    }
    for(int i=0;i<g[a].size();i++){
        if(!v[g[a][i]]){
            v[g[a][i]]=1;
            dfs2(g[a][i]);
        }
    }
    stk[T[a]].pop(); ord.pop_back();
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin>>T[i];
    for(int i=1, x, y;i<=N-1;i++){
        cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    dfs(1);
    for(int i=1, a, b, c;i<=M;i++){
        cin >> a >> b >> c;
        q[a].push_back(make_pair(i, make_pair(b, c)));
        q[b].push_back(make_pair(i, make_pair(a, c)));
    }
    memset(v, 0, sizeof(v));
    dfs2(1);
    for(int i=1;i<=M;i++) cout << ans[i];
    cout << endl;
    return 0;
}