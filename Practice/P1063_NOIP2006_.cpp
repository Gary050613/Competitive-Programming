// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int MM = 105;
int N, dp[2*MM][2*MM], a[MM], ans;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin>>a[i];
    // for(int i=1;i<=N;i++) dp[i][i] = a[i];
    for(int w=1;w<=N-1;w++){
        for(int l=1;l+w<=2*N;l++){
            int r = l+w;
            for(int k=l;k<r;k++){
                dp[l][r] = max(dp[l][r], dp[l][k]+dp[k+1][r]+a[(l-1)%N+1]*a[k%N+1]*a[r%N+1]);
            }
        }
    }
    // for(int i=1;i<=2*N;i++){
    //     for(int j=1;j<=2*N;j++) cout<<dp[i][j]<< " ";
    //     cout << endl;
    // }
    for(int i=1;i<=N;i++){
        ans = max(ans, dp[i][i+N-1]);
    }
    cout << ans << endl;
    return 0;
}