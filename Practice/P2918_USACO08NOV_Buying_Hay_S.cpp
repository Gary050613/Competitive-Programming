// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
const int MM = 5005;
int N, H, P[MM], C[MM], dp[55005], ans=INT_MAX;
int main(){
    cin >> N >> H;
    for(int i = 0;i<N;i++) cin >> P[i] >> C[i];
    for(int i=1;i<=55004;i++)dp[i]=55555;
    dp[0]=0;
    for(int i = 0;i<N;i++){
        for(int j=P[i];j<=55004;j++){
            dp[j] = min(dp[j-P[i]]+C[i], dp[j]);
        }
    }
    for(int i=H;i<=55004;i++){
        ans=min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}