#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M, from, to, arr[MM];
vector<int> g[MM];
int cnt=0;
char cow[MM], p;
bool visited[MM], ans=0;
// void dfs(int pos, bool G, bool H){
//     if(visited[pos]) return;
//     if(pos==to){
//         if(p=='G'&&G) ans=1;
//         else if(p=='H'&&H) ans=1;
//         return;
//     }
//     visited[pos]=1;
//     for(int i=0;i<g[pos].size();i++){
//         if(cow[g[pos][i]]=='G') dfs(g[pos][i], 1, H);
//         else if(cow[g[pos][i]]=='H') dfs(g[pos][i], G, 1);
//     }
// }
void update(int u, char ch){
    if(visited[u]) return;
    if(cow[u]!=ch) return;
    visited[u]=1;
    arr[u]=cnt;
    for(int i = 0;i<g[u].size();i++) update(g[u][i], ch);
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++)cin>>cow[i];
    for(int i=0, a, b;i<N-1;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0;i<N;i++){
        update(i, cow[i]);
        cnt++;
    }
    for(int i=0;i<M;i++){
        // memset(visited, 0, sizeof(visited));
        // ans=0;
        cin >> from >> to >> p;
        // cout << from << to << p;
        // if(cow[from]=='G') dfs(from, 1, 0);
        // else dfs(from, 0, 1);
        if(from == to){
            if(cow[from]==p) cout << 1;
            else cout << 0;
            continue;
        }
        if(cow[from]==p||cow[to]==p) cout << 1;
        else{
            if(arr[from]==arr[to]) cout << 0;
            else cout << 1;
        }
        // cout << endl;
        // cout<<ans;
    }
    return 0;
}