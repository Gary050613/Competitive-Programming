#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int M, N, v[MM], w[MM], dp[MM];
int main(){
    cin >> M >> N;
    for(int i=1;i<=N;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(j-w[i]>=0) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            else dp[j] = dp[j];
            // for(int k=0;k<=floor(j/w[i]);k++){
            //     dp[i][j] = max(dp[i][j], dp[i-1][j-k*w[i]]+k*v[i]);
            // }
        }
    }
    cout << dp[M] << endl;
    return 0;
}