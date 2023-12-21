#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
typedef long long ll;
typedef pair<ll, ll> pll;
ll N, ans=0, mx=0, mi=1e15+5, sum=0, a, v;
priority_queue<pll> pq;
int main(){
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a >> v;
        if(a>=mi&&a<=mx) sum+=v;
        else{
            if(pq.empty()) pq.push({a, v});
            else pq.push({a, v+pq.top().second});
            
        }
    }
    for(int i = 0;i<N;i++){
        else if(arr[i].second>arr[i].first){
            mx = max(mx, arr[i].first);
            mi = min(mi, arr[i].first);
            sum+=arr[i].second;
        }
    }
    cout << sum-mx+mi << endl;
    return 0;
}