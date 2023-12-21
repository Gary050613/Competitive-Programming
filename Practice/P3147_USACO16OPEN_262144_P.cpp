// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
const int MM = 262150;
int N, dp[MM][58], ans, a[MM];
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin>>a[i];
    memset(dp, -1, sizeof(dp));
    for(int n=1;n<=58;n++){
        for(int l=1;l<=N;l++){
            if(n == a[l]) dp[l][n] = l+1;
            else if(dp[l][n-1]!=-1&&dp[dp[l][n-1]][n-1]!=-1) dp[l][n] = dp[dp[l][n-1]][n-1];
            if(dp[l][n]!=-1) ans=max(ans, n);
        }
    }
    cout << ans << endl;
    return 0;
}