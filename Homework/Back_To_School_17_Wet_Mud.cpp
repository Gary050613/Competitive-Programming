#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, M, J, t[MM], p, ans=MM, dp[MM];
int main(){
    cin >> N >> M >> J;
    while(M--) {cin >> p; cin >> t[p];}
    // for(int i = 1;i<=N;i++) dp[i] = 0;
    // pos[i] = shortest time to reach i
    // dp[j] = max(t[j], dp[i]) if t[j]==0 then dp[j] = -1;
    for(int i = 1;i<=N;i++){
        if(t[i]==0) continue;
        for(int j = i+1;j<=i+J;j++){
            if(t[j]==0) continue;
            else t[j] = max(t[j], t[i]);
        }
    }
    for(int i = N-J+1;i<=N;i++){
        if(t[i]!=0) ans=min(t[i], ans);
    }
    if(ans == MM) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}