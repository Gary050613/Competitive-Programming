#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
const int add = 2000010;
typedef long long ll;
int N, Q, arr[MM];
// vector<int> st[2000100];
ll dp[MM][MM], cnt[4001000];
int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            // 0 = i + j + org
            // tar = add + org
            // org = -i-j
            int tar = add-arr[i]-arr[j];
            dp[i][j] = cnt[tar];
            cnt[arr[j]+add]++;
            // int l = min(i, j); int r = max(i, j);
            // for(int k=0;k<st[tar].size();k++){
            //     if(st[tar][k] == l || st[tar][k] == r) continue;
            //     l = min(l, st[tar][k]);
            //     r = max(r, st[tar][k]);
            //     // cout << i << " " << j << " " << st[tar][k] << endl;
            //     if(v[l][r]) continue;
            //     dp[l][r]++;
            //     v[l][r] = 1;
            //     // cout << l << " " << r << endl;
            // }
        }
        for (int j=i+1;j<=N;j++) cnt[arr[j]+add]--;
    }
    for(int k = 2;k<=N-1;k++){
        for(int l = 1;l<=N-k;l++){
            int r = l+k;
            dp[l][r] = dp[l][r] + dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1];
        }
    }
    int l, r;
    while(Q--){
        cin >> l >> r;
        cout << dp[l][r] << endl;
    }
    return 0;
}