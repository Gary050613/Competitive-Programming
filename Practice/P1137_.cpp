// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
const int MM = 100005;
int N, M, sz[MM];
bool v[MM];
vector<int> g[MM];
void dfs(int x){
    if(v[x]) return;
    v[x]=1;
    for(int i=0;i<g[x].size();i++){
        if(!v[g[x][i]]) dfs(g[x][i]);
        sz[x] = max(sz[x], sz[g[x][i]]+1);
    }
}
int main(){
    cin >> N >> M;
    for(int i=1, a, b;i<=M;i++){
        cin >> a >> b;
        g[b].push_back(a);
    }
    for(int i=1;i<=N;i++) sz[i]=1;
    for(int i=1;i<=N;i++) dfs(i);
    for(int i=1;i<=N;i++) cout << sz[i] << endl;
    return 0;
}