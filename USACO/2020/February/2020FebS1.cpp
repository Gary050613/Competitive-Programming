#include <bits/stdc++.h>
using namespace std;

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 1e5+5;
int N, M, K, m[MM], cycle[MM];
bool v[MM]={0};
vector<int> g;
int search(int u){
    if(v[u]) return 0;
    v[u]=1;
    g.push_back(u);
    return 1+search(m[u]);
}
int main(){
    setIO("swap");
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) m[i]=i;
    for(int i=0, l, r;i<M;i++){
        cin >> l >> r;
        while(l<r){
            swap(m[l], m[r]);
            l++, r--;
        }
    }
    // for(int i=1;i<=N;i++) cout << m[i] << " ";
    for(int i=1;i<=N;i++){
        if(!v[i]) {
            int a=K%search(i);
            // a = the ath number in the cycle since ith number
            for(int j=0;j<g.size();j++) cycle[g[j]] = g[(j+a)%g.size()];
            g.clear();
            // int u = i;
            // while(!cycle[u]) {cycle[u]=a; u=m[u];}
        }
    }
    for(int i=1;i<=N;i++) cout << cycle[i] << endl;
    // O(N)
    // for(int i=1;i<=N;i++){
    //     int target = K%cycle[i];
    //     int ans = i;
    //     // O(K%N)
    //     while(target--){
    //         ans=m[ans];
    //     }
    //     cout << ans << endl;
    // }
    return 0;
}