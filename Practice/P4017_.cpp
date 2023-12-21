// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int MM = 5005;
const ll MOD = 80112002;
ll N, M, ent[MM], ext[MM], ans, sz[MM];
vector<int> g[MM];
queue<int> q;
int main(){
    cin >> N >> M;
    for(int i=0, a, b;i<M;i++){
        cin >> a >> b;
        g[a].push_back(b); ent[b]++, ext[a]++;
    }
    for(int i=1;i<=N;i++){
        if(ent[i]==0&&ext[i]!=0) {q.push(i);sz[i]=1;}
    }
    while(!q.empty()){
        int cur = q.front();
        // ext[cur]--;
        for(int i=0;i<g[cur].size();i++){
            sz[g[cur][i]]=(sz[g[cur][i]]+sz[cur])%MOD;
            ent[g[cur][i]]--;
            if(ent[g[cur][i]]==0) {
                if(ext[g[cur][i]]==0) ans = (ans+sz[g[cur][i]])%MOD;
                else q.push(g[cur][i]);
            }
        }
        q.pop();
    }
    // for(int i=1;i<=N;i++) cout<<sz[i]<<" ";
    // cout << endl;
    // for(int i=1;i<=N;i++) cout<<ent[i]<<" ";
    // cout << endl;
    // for(int i=1;i<=N;i++) if(ext[i]==0) ans=(ans+sz[i])%MOD;
    cout << ans << endl;
    return 0;
}