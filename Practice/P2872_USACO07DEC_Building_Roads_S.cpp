#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int N, M, fa[MM];
double x[MM], y[MM], ans;
struct edge{
    double dis;
    int u;
    int v;
} edges[1000005];
int cnt=0;
bool cmp(edge a, edge b){
    return a.dis < b.dis;
}
int find(int a){
    if(fa[a]==a) return a;
    else{
        fa[a] = find(fa[a]);
        return fa[a];
    }
}
void merge(int a, int b){
    fa[find(a)] = find(b);
}
int main(){
    cin >> N >> M;
    for(int i=1, u , v;i<=N;i++){
        cin >> u >> v;
        x[i]=u, y[i]=v;
        fa[i]=i;
    }
    for(int i=1, u, v;i<=M;i++){
        cin >> u >> v;
        merge(u, v);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(find(i)==find(j)) continue;
            else{
                edges[cnt].u = i;
                edges[cnt].v = j;
                edges[cnt++].dis = sqrt(abs(x[i]-x[j])*abs(x[i]-x[j])+abs(y[i]-y[j])*abs(y[i]-y[j]));
            }
        }
    }
    sort(edges, edges+cnt, cmp);
    for(int i=0;i<cnt;i++){
        if(find(edges[i].u)==find(edges[i].v)) continue;
        else{
            ans+=edges[i].dis;
            merge(edges[i].u, edges[i].v);
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}