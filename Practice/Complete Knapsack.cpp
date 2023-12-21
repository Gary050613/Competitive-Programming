#include <bits/stdc++.h>
using namespace std;
int N, C, dp[20][20]={0}, w[10], v[10];
int main(){
    // dp[i][j] = max(dp[i-1][j-k*w[i]]+k*v[i])
    cin >> N >> C;
    for(int i=1;i<=N;i++) cin >> w[i] >> v[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=C;j++){
            for(int k=0;k<=floor(j/w[i]);k++){
                dp[i][j] = max(dp[i][j], dp[i-1][j-k*w[i]]+k*v[i]);
            }
        }
    }
    // for(int i = 0;i<N;i++){
    //     for(int j=0;j<=C;j++) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    cout << dp[N-1][C] << endl;
    return 0;
}