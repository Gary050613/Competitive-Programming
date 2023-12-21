#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+5;
int N, M, LOW[MM], DFN[MM], cnt=0, out[MM], ans=0, color[MM], col=1, v[MM], sz[MM];
bool inS[MM];
vector<int> g[MM], g1[MM];
stack<int> stk;
pair<int, int> edges[MM];
void tarjan(int a){
    DFN[a] = ++cnt;
    LOW[a] = DFN[a];
    inS[a] = 1;
    stk.push(a);
    for(int i=0;i<g[a].size();i++){
        int b = g[a][i];
        if(!DFN[b]){
            tarjan(b);
            LOW[a] = min(LOW[a],LOW[b]);
        }else if(inS[b]){
            LOW[a] = min(LOW[a], DFN[b]);
        }
    }
    if(LOW[a]==DFN[a]){
        while(stk.top()!=a){
            inS[stk.top()]=0;
            color[stk.top()]=col;
            sz[col]++;
            stk.pop();
        }
        inS[stk.top()]=0;
        sz[col]++;
        color[stk.top()]=col++;
        stk.pop();
    }
    return;
}
// void dfs(int a){
//     v[a]=1;
//     for(int i=0;i<g1[a].size();i++){
//         int b = g1[a][i];
//         if(!v[b]){
//             dfs(b);
//         }
//     }
// }
int main(){
    cin >> N >> M;
    for(int i=0, a, b;i<M;i++){
        cin >> a >> b;
        g[a].push_back(b);
        edges[i]={a, b};
    }
    for(int i=1;i<=N;i++) if(DFN[i]==0) tarjan(i);
    // for(int i=1;i<=N;i++) if(v[i]==0) {v[i]=1; dfs(i);}
    for(int i=0;i<M;i++){
        if(color[edges[i].first]!=color[edges[i].second]) {
            out[color[edges[i].first]]++;
            // g1[color[edges[i].first]].push_back(color[edges[i].second]);
            // g1[color[edges[i].second]].push_back(color[edges[i].first]);
        }
    }
    // for(int i=1;i<=N;i++) if(!v[i]){ cout << 0 << endl; return 0;}
    // dfs(1);
    // for(int i=1;i<col;i++){
    //     if(!v[i]){cout << 0 << endl; return 0;}
    // }
    for(int i=1;i<col;i++) {
        if(out[i]==0&&ans>0){cout << 0 << endl; return 0;}
        if(out[i]==0) ans+=sz[i];
    }
    cout << ans << endl;
    return 0;
}