#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 105;
int N, P, C[MM], U[MM], ent[MM], ext[MM];
vector<pii> g[MM];
queue<int> q;
int main(){
    cin >> N >> P;
    for(int i=1;i<=N;i++){
        cin >> C[i] >> U[i];
        if(C[i]!=0) U[i]=0;
    }
    for(int i=1, a, b, w;i<=P;i++){
        cin >> a >> b >> w;
        ent[b]++, ext[a]++;
        g[a].push_back({b, w});
    }
    for(int i=1;i<=N;i++)
        if(ent[i]==0)
            q.push(i);
    while(!q.empty()){
        int cur = q.front();
        C[cur]-=U[cur];
        if(C[cur]){
            for(int i=0;i<g[cur].size();i++){
                ent[g[cur][i].first]--;
                C[g[cur][i].first] += C[cur]*g[cur][i].second;
                if(ent[g[cur][i].first]==0) q.push(g[cur][i].first);
            }
        }
        q.pop();
    }
    bool flag=0;
    for(int i=1;i<=N;i++){
        if(ext[i]==0){
            if(C[i]) {flag=1; cout << i << " " << C[i] << endl;}
        }
    }
    if(!flag) cout<<"NULL\n";
    return 0;
}