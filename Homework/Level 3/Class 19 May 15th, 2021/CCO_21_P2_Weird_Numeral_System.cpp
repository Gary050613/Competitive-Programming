#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5003;
int K, Q, D, M, a[MM]; ll n; vector<ll> path; unordered_set<ll> vis; bool recur = 0;

bool dfs(ll n){
    if(n == 0 && recur) return true;
    if(vis.count(n)) return false;
    vis.insert(n); recur = true;
    for(int i = 0;i<D;i++){
        if((n-a[i])%K==0){
            if(dfs((n-a[i])/K)){ path.push_back(a[i]); return true;}
        }
    }
    return false;
}

int main(){
    cin >> K >> Q >> D >> M;
    for(int i = 0;i<D;i++) cin >> a[i];
    for(int i = 1;i<=Q;i++){
        cin >> n; path.clear(); vis.clear(); recur=0;
        if(!dfs(n)) cout << "IMPOSSIBLE\n";
        else{
            for(int j=0;j<path.size();j++)
                cout << path[j] << (j==(int)path.size()-1 ? "\n": " ");
        }
    }
    return 0;
}