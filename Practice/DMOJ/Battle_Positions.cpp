#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
ll I, N, J, a, b, K, diff[MM]={0};
int main(){
    cin >> I >> N >> J;
    while(J--){
        cin >> a >> b >> K;
        diff[a]+=K, diff[b+1]-=K;
    }
    ll ans = 0, cur=0;
    for(ll i = 1;i<=I;i++){
        cur += diff[i];
        if(cur < N) ans++;
    }
    cout << ans << endl;
    return 0;
}