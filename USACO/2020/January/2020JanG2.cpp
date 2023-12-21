#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 5005;
const int add = 1000010;
typedef long long ll;
int N, Q, arr[MM];
// vector<int> st[2000100];
ll dp[MM][MM], cnt[2001000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setIO("threesum");
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            int tar = add-arr[i]-arr[j];
            if(tar >= 10 && tar <= 1000000+add) dp[i][j] = cnt[tar];
            cnt[arr[j]+add]++;
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