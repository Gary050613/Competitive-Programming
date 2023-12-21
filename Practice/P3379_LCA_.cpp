// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MM = 500005;
int N, M, S, f[MM][21], depth[MM], fa[MM];
bool v[MM];
vector<int> g[MM];
void dfs(int a){
    for(int i=0;i<g[a].size();i++){
        if(!v[g[a][i]]){
            v[a]=1;
            depth[g[a][i]] = depth[a]+1;
            fa[g[a][i]] = a;
            dfs(g[a][i]);
        }
    }
}
int main(){
    cin >> N >> M >> S;
    for(int i=0, a, b;i<N-1;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth[S]=1;
    dfs(S);
    // cout << endl;
    for(int i=0;i<20;i++){
        for(int a=1;a<=N;a++){
            if((1<<i)<depth[a]){
                if(i==0) f[a][i] = fa[a];
                else f[a][i] = f[f[a][i-1]][i-1];
            }
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=20;j++) cout << f[i][j] << " ";
    //     cout << endl;
    // }
    int a, b;
    while(M--){
        cin >> a >> b;
        if(depth[a]>depth[b]){
            for(int i=20;i>=0;i--){
                if(depth[f[a][i]]>=depth[b]) a=f[a][i];
            }
        }else{
            for(int i=20;i>=0;i--){
                if(depth[f[b][i]]>=depth[a]) b=f[b][i];
            }
        }
        // cout << a << " " << b << endl;
        for(int i=20;i>=0;i--){
            if(f[a][i]!=f[b][i]){
                a = f[a][i], b = f[b][i];
            }
        }
        if(a==b) cout << a << endl;
        else cout << f[a][0] << endl;
    }
    return 0;
}