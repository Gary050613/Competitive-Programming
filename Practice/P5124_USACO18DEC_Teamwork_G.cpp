#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, K, dp[MM], a[MM];
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> a[i];
    dp[1] = a[1];
    for(int i=1;i<=N;i++){
        int mx=0;
        for(int j=1;j<=K&&i-j>=0;j++){
            mx = max(mx, a[i-j+1]);
            dp[i] = max(dp[i], dp[i-j]+j*mx);
        }
    }
    // for(int i=1;i<=N;i++) cout << dp[i] << " ";
    cout << dp[N] << endl;
    return 0;
}