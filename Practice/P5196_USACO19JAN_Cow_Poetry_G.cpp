#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
const int MOD = 1000000007;
typedef long long ll;
ll N, M, K, f[MM], cnt[MM], g[MM], s[MM], c[MM], po[30];
ll ans=1;
ll fpow(ll x, ll a){
    ll result = 1, base = x;
    while(a){
        if(a&1) {result=(result*base)%MOD;}
        base = (base*base)%MOD;
        a=a>>1;
    }
    return result;
}
int main(){
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        cin >> s[i] >> c[i];
        cnt[s[i]]++;
    }
    f[0]=1;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=i;j++){
            f[i] = (f[i]+f[i-j]*cnt[j])%MOD;
        }
    }
    // for(int i=1;i<=K;i++) cout<<f[i]<<" ";
    for(int i=1;i<=N;i++){
        g[c[i]] = (g[c[i]]+f[K-s[i]])%MOD;
    }
    for(int i=1;i<=M;i++){
        char ch;
        cin >> ch;
        po[ch-'A']++;
    }
    for(int a=0;a<26;a++){
        ll sum=0;
        if(po[a]){
            for(int i=1;i<=N;i++){
                sum = (sum+fpow(g[i],po[a]))%MOD;
                // cout << g[i] << " " << po[a] << endl;
                // cout << sum << endl;
            }
            ans = (ans*sum)%MOD;
        }
    }
    cout << ans << endl;
    return 0;
}