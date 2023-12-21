// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MM = 55;
const ll mx = 1e17;
ll N, c, dp[MM][MM][2], p[MM], w[MM];
int main(){
    cin >> N >> c;
    for(int i=1;i<=N;i++){
        cin >> p[i] >> w[i];
    }
    for(int i=0;i<55;i++){
        for(int j=0;j<55;j++) {dp[i][j][0] = mx; dp[i][j][1] = mx;}
    }
    for(int i=1;i<=N;i++) w[i] = w[i-1] + w[i];
    dp[c][c][0]=0;
    dp[c][c][1]=0;
    for(int a=1;a<=N-1;a++){
        for(int l=1;l+a<=N;l++){
            int r = l+a;
            if(c>=l&&c<=r){
                dp[l][r][0] = min(dp[l+1][r][0]+(p[l+1]-p[l])*(w[l]+w[N]-w[r]), dp[l+1][r][1]+(p[r]-p[l])*(w[l]+w[N]-w[r]));
                dp[l][r][1] = min(dp[l][r-1][0]+(p[r]-p[l])*(w[l-1]+w[N]-w[r-1]), dp[l][r-1][1]+(p[r]-p[r-1])*(w[l-1]+w[N]-w[r-1]));
            }
        }
    }
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5;j++) cout<<s[i][j][1]<<" ";
    //     cout << endl;
    // }
    if(dp[1][N][0]<dp[1][N][1]) cout<<dp[1][N][0]<<endl;
    else cout<<dp[1][N][1]<<endl;
    return 0;
}