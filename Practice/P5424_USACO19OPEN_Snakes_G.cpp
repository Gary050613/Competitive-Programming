#include <bits/stdc++.h>
using namespace std;
const int MX = 1e9;
const int MM = 405;
int N, K, dp[MM][MM], psa[MM], a[MM];
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){cin >> a[i]; psa[i] = a[i];}
    for(int i=1;i<=N;i++) psa[i] += psa[i-1];
    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++) dp[i][j] = MX;
    }
    for(int j=1;j<=K;j++) dp[1][j] = 0;
    int cur = a[1];
    for(int i=1;i<=N;i++){
        cur = max(cur, a[i]);
        dp[i][0] = min(dp[i][0], cur*i-psa[i]);
    }
    // for(int i=1;i<=N;i++) cout << dp[i][0] << " ";
    // cout << endl;
    for(int j=1;j<=K;j++){
        for(int i=2;i<=N;i++){
            int mx = a[i];
            for(int k=i-1;k>0;k--){
                dp[i][j] = min(dp[i][j], dp[k][j-1]+mx*(i-k)-(psa[i]-psa[k]));
                // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j] << endl;
                mx = max(mx, a[k]);
            }
        }
    }
    // for(int j=1;j<=K;j++){
    //     for(int i=1;i<=N;i++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[N][K] << endl;
    return 0;
}