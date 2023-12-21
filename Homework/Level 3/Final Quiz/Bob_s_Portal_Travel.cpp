#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
ll N, K, portal[MM], dp[MM], vis[MM]={0}, loop = 0;
unordered_set<int> st;
// dp[n] = How many needed for a loop;
int fill(int from, int to, int cnt){
    if(from == to) return 0;
    if(dp[to]!=-1)
    if(cnt > N || st.count(to)){
        loop = 1;
        return -1;
    }
    st.insert(to);
    return 1+fill(from,portal[to], cnt+1);
}
int main(){
    cin >> N >> K;
    for(int i = 1;i<=N;i++) cin >> portal[i];
    memset(dp, -1, sizeof(dp));
    st.clear();
    loop = 0;
    dp[1] = 1+fill(i, portal[1], 1);
    if(loop) dp[i] = -1;
    int cur = 1;
    while(K>0){
        // cout << cur << " ";
        if(dp[cur]!=-1){ K%=dp[cur];} // Finish cycling
        if(K==0) break;
        cur = portal[cur];
        K--;
    }
    // cout << endl;
    // for(int i = 1;i<=N;i++) cout << dp[i] << " ";
    // cout << endl;
    cout << cur << endl;
    return 0;
}