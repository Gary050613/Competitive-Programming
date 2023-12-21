#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int N, psa[MM], arr[MM], dp[MM][MM];
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) {cin >> arr[i]; dp[i][i]=arr[i];}
    for(int i=1;i<=N;i++) psa[i]=psa[i-1]+arr[i];
    for(int r=1;r<=N;r++){
        for(int i=1;i+r<=N;i++){
            int j=i+r;
            dp[i][j] = max(psa[j]-psa[i]-dp[i+1][j]+arr[i], psa[j-1]-psa[i-1]-dp[i][j-1]+arr[j]);
        }
    }
    cout << dp[1][N] << " " << psa[N]-dp[1][N] << endl;
    return 0;
}