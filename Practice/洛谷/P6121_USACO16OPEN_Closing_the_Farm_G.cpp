#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, M, father[MM], u, v, arr[MM], cur;
bool ans[MM], visited[MM];
vector<int> g[MM];
int find(int u){
    if(father[u]==u) return u;
    else{
        father[u] = find(father[u]);
        return father[u];
    }
}
void merge(int a, int b){
    father[find(a)]=find(b);
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++) father[i]=i;
    while(M--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<N;i++) cin >> arr[i];
    cur=1;
    visited[arr[N-1]]=1;
    ans[N-1]=1;
    for(int i=N-2;i>=0;i--){
        visited[arr[i]]=1;
        cur++;
        for(int j=0;j<g[arr[i]].size();j++){
            if(visited[g[arr[i]][j]] && find(g[arr[i]][j])!=find(arr[i])) {merge(g[arr[i]][j], arr[i]);cur--;}
        }
        if(cur==1) ans[i]=1;
        else ans[i]=0;
    }
    for(int i=0;i<N;i++)
        if(ans[i]) cout<<"YES\n";
        else cout<<"NO\n";
    return 0;
}