#include <bits/stdc++.h>
using namespace std;
const int MM = 250;
int N, arr[MM], dp[MM][MM], ans=0;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) {cin>>arr[i]; dp[i][i]=arr[i], ans=max(ans, arr[i]);}
    for(int r=1;r<=N;r++){
        for(int i=1;i+r<=N;i++){
            int k = i+r;
            for(int j=i;j<k;j++){
                if(dp[i][j]==dp[j+1][k]) {dp[i][k] = max(dp[i][k], dp[i][j]+1); ans=max(ans, dp[i][k]);}
            }
        }
    }
    cout << ans << endl;
    return 0;
}