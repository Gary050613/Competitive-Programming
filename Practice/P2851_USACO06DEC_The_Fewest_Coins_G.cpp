#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int T, N, v[MM], cnt[125], dp[2*MM][125], ans=INT_MAX;
unordered_set<int> st;
int main(){
    cin >> N >> T;
    for(int i=1;i<=N;i++) {cin >> v[i]; st.insert(v[i]);}
    for(int i=1;i<=N;i++) cin >> cnt[i];
    for(int i=1;i<=2*T;i++) dp[i]
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=2*T;j++){
            // dp[j]=-1, dp[j-v[i]]=-1
            // dp[j] = min(dp[j], dp[j-v[i]]+1);
            if(j>=v[i]){
                if(dp[j]==-1&&dp[j-v[i]]!=-1&&cnt[i]) dp[j] = dp[j-v[i]]+1, cnt[i]--;
                else if(dp[j]!=-1&&dp[j-v[i]]!=-1&&cnt[i]){
                    if(dp[j-v[i]]+1<dp[j]) dp[j] = dp[j-v[i]]+1, cnt[i]--;
                }
            }
        }
    }
    for(int i=1;i<=2*T;i++) cout << dp[i] << " ";
    return 0;
}