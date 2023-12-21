#include <bits/stdc++.h>
using namespace std;
const int MX = 1e9+5;
const int MM = 105;
int M, Q, a[MM], dp[MM][MM][2], ans=MX, pt;
string arr[MM], txt="\n";
int main(){
    cin >> M >> Q;
    for(int i=1;i<=Q;i++) cin >> arr[i] >> a[i];
    for(int i=0;i<=Q;i++){
        for(int j=0;j<=Q;j++) dp[i][j][0] = MX;
    }
    dp[0][0][0]=0;
    for(int j=1;j<=Q;j++){
        for(int i=1;i<=Q;i++){
            int mx = a[i];
            for(int k=i-1;k>=i-M;k--){
                if(dp[k][j-1][0]+mx<dp[i][j][0]){
                    dp[i][j][0] = dp[k][j-1][0]+mx;
                    dp[i][j][1] = k+1;
                }
                mx = max(mx, a[k]);
            }
        }
    }
    // for(int j=1;j<=Q;j++){
    //     for(int i=1;i<=Q;i++) cout << dp[i][j][1] << " ";
    //     cout << endl;
    // }
    for(int j=Q;j>=1;j--){
        if(dp[Q][j][0] <= ans){
            ans = dp[Q][j][0];
            pt = j;
        }
    }
    printf("Total Time: %d", ans);
    int cur = Q, last;
    while(Q>=1){
        last = dp[Q][pt][1];
        // cout << Q << " " << last << endl;
        pt--;
        while(Q>=last){
            txt = arr[Q] + " " + txt;
            Q--;
        }
        txt = "\n" + txt;
    }
    cout << txt;
    return 0;
}