#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
const int MAX = 1e9+5;
int N, dp[MM][MM], h[MM], ans[MM];
int main(){
    cin >> N;
    for(int i=2;i<=N;i++){
        ans[i] = MAX;
    }
    for(int i=1;i<=N;i++){
        cin >> h[i];
    }
    for(int i=1;i<=N-1;i++){
        dp[i][i+1] = abs(h[i]-h[i+1]);
        ans[2] = min(ans[2], dp[i][i+1]);
    }
    for(int w=2;w<=N-1;w++){
        for(int l=1;l+w<=N;l++){
            int r = l+w;
            dp[l][r] = dp[l+1][r-1] + abs(h[l]-h[r]);
            ans[w+1] = min(ans[w+1], dp[l][r]);
        }
    }
    for(int i=1;i<=N;i++) cout << ans[i] << " ";
    return 0;
}