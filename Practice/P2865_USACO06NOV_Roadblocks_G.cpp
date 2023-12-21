#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
typedef pair<int, int> ii;
int N, R, a[MM], b[MM], pre[MM], nxt[MM], ans=1000000000;
bool v[MM];
vector<ii> g[MM];
struct priority{
    int x;
    int d;
    int from;
    bool operator <(const priority &x)const{
        return d>x.d;
    }
};
priority_queue<priority> pq;
int main(){
    cin >> N >> R;
    for(int i=1, A, B, D;i<=R;i++){
        cin >> A >> B >> D;
        // if(mp[A][B]==0) mp[A][B] = mp[B][A] = D;
        // else {mp[A][B] = min(mp[A][B], D); mp[B][A] = min(mp[B][A], D);}
        g[A].push_back({B, D});
        g[B].push_back({A, D});
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<g[i].size();j++){
    //         cout << g[i][j].first << " ";
    //     }
    //     cout << endl;
    // }
    pq.push((priority){1, 0, 0});
    while(!pq.empty()){
        int cur = pq.top().x;
        int dis = pq.top().d;
        // cout << cur << endl;
        pq.pop();
        if(!v[cur]){
            v[cur] = 1;
            a[cur] = dis;
            for(int i=0;i<g[cur].size();i++){
                pq.push((priority){g[cur][i].first, dis+g[cur][i].second, cur});
            }
        }
    }
    memset(v, 0, sizeof(v));
    pq.push((priority){N, 0, 10000});
    while(!pq.empty()){
        int cur = pq.top().x;
        int dis = pq.top().d;
        int from = pq.top().from;
        // cout << from << endl;
        pq.pop();
        if(!v[cur]){
            v[cur] = 1;
            b[cur] = dis;
            nxt[cur] = from;
            for(int i=0;i<g[cur].size();i++){
                pq.push((priority){g[cur][i].first, dis+g[cur][i].second, cur});
            }
        }
    }
    // for(int i=1;i<=N;i++) cout << a[i] << " ";
    int c = 1;
    while(c!=10000){
        for(int i=0;i<g[c].size();i++){
            // cout << g[c][i].first << endl;
            if (a[c]+g[c][i].second+b[g[c][i].first] > a[N]) ans = min(ans, a[c]+g[c][i].second+b[g[c][i].first]);
        }
        // nxt[pre[c]] = c;
        c = nxt[c];
    }
    cout << ans << endl;
    return 0;
}