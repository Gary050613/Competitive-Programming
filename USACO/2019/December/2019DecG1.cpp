#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 1005;
typedef pair<double, double> dd;
int N, M;
bool v[MM];
double ans[MM];
struct priority{
    int cur;
    double c;
    double f;
    bool operator <(const priority &x) const{
        return (f/c)<(x.f/x.c);
    }
};
priority_queue<priority> pq;
vector<pair<int, dd> > g[MM];
int main(){
    setIO("pump");
    cin >> N >> M;
    for(int i=1, a, b, c, f;i<=M;i++){
        cin >> a >> b >> c >> f;
        g[a].push_back({b, {c, f}});
        g[b].push_back({a, {c, f}});
    }
    v[1] = 1;
    for(int j=0;j<g[1].size();j++){
        pq.push((priority){g[1][j].first, g[1][j].second.first, g[1][j].second.second});
    }
    while(!pq.empty()){
        if(!v[pq.top().cur]){
            int cur = pq.top().cur;
            double cost = pq.top().c;
            double len = pq.top().f;
            v[cur] = 1;
            ans[cur] = len/cost;
            pq.pop();
            for(int i=0;i<g[cur].size();i++){
                pq.push((priority){g[cur][i].first, cost+g[cur][i].second.first, min(g[cur][i].second.second, len)});
            }
        }
        else pq.pop();
    }
    cout << floor(ans[N]*1000000) << endl;
    return 0;
}