#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const int MM = 1e5+5;
ll N, M, S, dij[MM];
bool v[MM];
struct priority
{
    int first;
    int second;
    bool operator <(const priority &x)const
    {
        return x.first<first;
    }
};
priority_queue<priority> pq;
vector<ii> g[MM];
int main(){
    cin >> N >> M >> S;
    for(int i=1, u, v, w;i<=M;i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    pq.push((priority){0, S});
    while(!pq.empty()){
        int cur = pq.top().second;
        if(!v[cur]){
            v[cur] = 1;
            dij[cur] = pq.top().first;
            for(int i=0;i<g[cur].size();i++){
                pq.push((priority){(dij[cur]+g[cur][i].second), g[cur][i].first});
            }
        }
        pq.pop();
    }
    for(int i=1;i<=N;i++) cout << dij[i] << " ";
    return 0;
}