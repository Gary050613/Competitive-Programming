#include <bits/stdc++.h>
using namespace std;

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 2505;
int N, c[MM], h[MM], od, ev;
bool v[MM];
vector<int> g[MM];
int dfs(int u){
    v[u]=1;
    for(int i=0;i<g[u].size();i++){
            if(v[g[u][i]]) continue;
            //before enter g[u][i]
            h[g[u][i]]=h[u]+1;

            dfs(g[u][i]);

            //backtracking from g[u][i]
            c[u]=(c[u]-c[g[u][i]]+12)%12;
            c[g[u][i]] = 0;
        }   
}
int main(){
    setIO("clocktree");
    cin >> N;
    for(int i=1;i<=N;i++) {cin>>c[i];c[i]=(12-c[i])%12;}
    for(int i=0, u, v;i<N-1;i++){
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    h[1]=0;
    dfs(1);
    // for(int i=1;i<=N;i++) cout << h[i] << " ";
    for(int i=1;i<=N;i++)
        if(h[i]%2==1) od++;
        else ev++;
    // cout << c[1]%12 << endl;
    if(c[1]==0) cout << N << endl;
    else if(c[1]%12==1){
        cout << od << endl;
    }else if(c[1]==11||c[1]==-1){
        cout << ev << endl;
    }else cout << 0 << endl;
    // for(int i=1;i<=N;i++) cout << c[i] << " ";
    return 0;
}