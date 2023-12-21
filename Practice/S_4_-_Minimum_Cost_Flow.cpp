#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
const int NM = 1e5+5;
typedef pair<int, int> ii;
int N, M, D, fa[NM], ans;
struct edge{
    int u, v, a, cnt;
} e[MM];
// vector<ii> g[MM];
bool cmp(edge a, edge b){
    if(a.a < b.a) return true;
    else if(a.a == b.a) return a.cnt < b.cnt;
    return false;
}
int find(int x){
    if(fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
void uni(int x, int y){
    fa[find(x)] = find(y);
}
int main(){
    cin >> N >> M >> D;
    for(int i=1, u, v, a;i<=M;i++){
        cin >> e[i].u >> e[i].v >> e[i].a;
        e[i].cnt = i;
    }
    sort(e+1, e+1+M, cmp);
    for(int i=1;i<=N;i++) fa[i]=i;
    for(int i=1;i<=M;i++){
        if(find(e[i].u)!=find(e[i].v)){
            uni(e[i].u, e[i].v);
            if(e[i].cnt > N-1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}