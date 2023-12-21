#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const int MM = 1e5+5;
ll N, M, S, dij[MM];
bool v[MM];
priority_queue<ii> pq;
vector<ii> g[MM];
int main(){
    cin >> N >> M >> S;
    for(int i=1, u, v, w;i<=M;i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for(int i=1;i<=N;i++) dij[i] = 2147483647;
    pq.push({0, S});
    while(!pq.empty()){
        int cur = pq.top().second;
        if(!v[cur]){
            v[cur] = 1;
            dij[cur] = pq.top().first*-1;
            for(int i=0;i<g[cur].size();i++){
                pq.push({-1*(dij[cur]+g[cur][i].second), g[cur][i].first});
            }
        }
        pq.pop();
    }
    for(int i=1;i<=N;i++) cout << dij[i] << " ";
    return 0;
}