#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
struct priority{
    int dis;
    int id;
    bool operator <(const priority &x)const
    {
        return x.dis<dis;
    }
};
const int MM = 1e3+5;
int N, M, dij[MM], dij1[MM], ans, arr[MM][MM];
bool v[MM];
priority_queue<priority> pq;
vector<ii> g[MM], g1[MM];
int main(){
    cin >> N >> M;
    for(int i=1, a, b, x;i<=M;i++){
        cin >> a >> b >> x;
        if(arr[a][b]) arr[a][b] = min(arr[a][b], x);
        else arr[a][b] = x;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j]) {g[i].push_back({j, arr[i][j]});g1[j].push_back({i, arr[i][j]});}
        }
    }
    pq.push((priority){0, 1});
    while(!pq.empty()){
        int cur = pq.top().id;
        int d = pq.top().dis;
        pq.pop();
        if(!v[cur]){
            v[cur] = 1;
            dij[cur] = d;
            for(int i=0;i<g[cur].size();i++){
                pq.push((priority){dij[cur]+g[cur][i].second, g[cur][i].first});
            }
        }
    }
    pq.push((priority){0, 1});
    memset(v, 0, sizeof(v));
    while(!pq.empty()){
        int cur = pq.top().id;
        int d = pq.top().dis;
        pq.pop();
        if(!v[cur]){
            v[cur] = 1;
            dij1[cur] = d;
            for(int i=0;i<g1[cur].size();i++){
                pq.push((priority){dij1[cur]+g1[cur][i].second, g1[cur][i].first});
            }
        }
    }
    // for(int i=1;i<=N;i++) cout << dij[i] << " ";
    // cout << endl;
    for(int i=2;i<=N;i++) ans+=dij[i]+dij1[i];
    cout << ans << endl;
    return 0;
}