#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e5+5;
const int mx = 1e9+5;
ll n, K, t[MM]={0}, x[MM], y[MM], ans=0;
int main(){
    cin >> n >> K;
    for(int i = 1;i<=n;i++) cin >> t[i] >> x[i] >> y[i];
    ll l=mx, r=mx*-1;
    for(int i = 1;i<=n;i++){
        l += (t[i]-t[i-1])*K, r -= (t[i]-t[i-1])*K;
        l = min(l, x[i]); r = max(r, x[i]);
        ans = max(ans, r-l);
    }
    l=mx, r=mx*-1;
    for(int i = 1;i<=n;i++){
        l += (t[i]-t[i-1])*K, r -= (t[i]-t[i-1])*K;
        l = min(l, y[i]); r = max(r, y[i]);
        ans = max(ans, r-l);
    }
    cout << ans << endl;
    return 0;
}