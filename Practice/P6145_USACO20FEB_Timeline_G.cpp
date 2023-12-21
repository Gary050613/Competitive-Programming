#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MM = 1e5+5;
int N, M, C, S[MM], ans[MM], ent[MM], ext[MM];
vector<ii> g[MM];
queue<int> q;
int main(){
    cin >> N >> M >> C;
    for(int i=1;i<=N;i++) cin>>S[i];
    for(int i=1, a, b, x;i<=C;i++){
        cin >> a >> b >> x;
        ent[b]++; ext[a]++;
        g[a].push_back({b, x});
    }
    for(int i=1;i<=N;i++){
        if(ent[i]==0) {q.push(i);}
        ans[i] = S[i];
    }
    while(!q.empty()){
        int cur = q.front();
        for(int i=0;i<g[cur].size();i++){
            ent[g[cur][i].first]--;
            ans[g[cur][i].first] = max(ans[g[cur][i].first], ans[cur]+g[cur][i].second);
            if(ent[g[cur][i].first]==0) q.push(g[cur][i].first);
        }
        q.pop();
    }
    for(int i=1;i<=N;i++) cout << ans[i] << endl;
    return 0;
}