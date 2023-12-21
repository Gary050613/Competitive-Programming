#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M, p[MM], ans=INT_MAX, fa[MM];
bool v[MM];
pair<int, pair<int, int> > arr[MM];
// vector<int> g[MM];
// O(N)
// bool search(int u, int target){
//     if(u==target) return true;
//     if(v[u]) return false;
//     v[u]=1;
//     bool flag=0;
//     for(int i=0;i<g[u].size();i++) flag|=search(g[u][i], target);
//     return flag;
// }
int find(int u){
    if(fa[u]==u) return u;
    fa[u]=find(fa[u]);
    return fa[u];
}
int merge(int a, int b){
    fa[find(a)]=find(b);
}
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){return a.first > b.first;}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++) {cin>>p[i];fa[i]=i;}
    for(int i=0, a, b, w;i<M;i++){
        cin >> a >> b >> w;
        arr[i]={w, {a, b}};
    }
    sort(arr, arr+M, cmp);
    int counter = 0;
    // O(N)
    // for(int i=1;i<=N;i++){
    //     memset(v, 0, sizeof(v));
    //     // O(M)
    //     while(counter<M&&!search(i, p[i])){
    //         g[arr[counter].second.first].push_back(arr[counter].second.second);
    //         g[arr[counter].second.second].push_back(arr[counter].second.first);
    //         ans=min(ans, arr[counter].first);
    //         counter++; memset(v, 0, sizeof(v));
    //     }
    // }
    for(int i=1;i<=N;i++){
        while(counter<M&&find(i)!=find(p[i])){
            merge(arr[counter].second.first, arr[counter].second.second);
            ans=min(ans, arr[counter].first);
            counter++;
        }
    }
    if(ans==INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}