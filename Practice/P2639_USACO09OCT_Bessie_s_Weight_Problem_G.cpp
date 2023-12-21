#include <bits/stdc++.h>
using namespace std;
const int MM = 45005;
int H, N, dp[505][MM]={0}, w[505];
int main(){
    cin >> H >> N;
    for(int i=1;i<=N;i++) cin >> w[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=H;j++){
            if(j>=w[i]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+w[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[N][H] << endl;
    return 0;
}