#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
ll N, K, M, step[MM], cycle[MM], cnt=0, ans[MM]={0}, last[MM], f[200005], s[200005];
bool v[MM];
vector<int> g[MM], q;
set<int> st[MM];
void init(int u){
    if(v[u]) return;
    v[u]=1; cnt++;
    q.push_back(u);
    int pos = q.size()-1;
    init(step[u]);
    cycle[u]=cnt;
    last[u]=q[((M/K)+pos)%cycle[u]];
}
void dfs(int s, int u, ll rounds){
    if(rounds<=0) {return;}
    st[s].insert(u);
    for(int i=0;i<g[u].size();i++){
        st[s].insert(g[u][i]);
    }
    dfs(s, step[u], rounds-1);
}
int main(){
    cin >> N >> K >> M;
    for(int i=1;i<=N;i++) {step[i]=i;last[i]=i;}
    for(int i=1;i<=K;i++){
        cin >> f[i] >> s[i];
        g[step[f[i]]].push_back(s[i]);
        g[step[s[i]]].push_back(f[i]);
        swap(step[f[i]], step[s[i]]);
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<g[i].size();j++) cout << g[i][j] << " ";
    //     cout << endl;
    // }
    // for(int i=1;i<=N;i++) cout << step[i] << " ";
    for(int i=1;i<=N;i++) if(!cycle[i]) {cnt=0; init(i);}
    // for(int i=1;i<=N;i++) cout << cycle[i] << " ";
    memset(v, 0, sizeof(v));
    for(int i=1;i<=N;i++){
        if(st[i].empty()){
            if(M/K<cycle[i]) dfs(i, i, M/K);
            else dfs(i, i, cycle[i]);
        }
    }
    for(int i=1;i<=M%K;i++){
        // cout << last[f[i]] << " " << last[s[i]] << endl;
        st[last[f[i]]].insert(s[i]);
        st[last[s[i]]].insert(f[i]);
        swap(last[f[i]], last[s[i]]);
    }
    for(int i=1;i<=N;i++) cout << st[i].size() << endl;
    return 0;
}