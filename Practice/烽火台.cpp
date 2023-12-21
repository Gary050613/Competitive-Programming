// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int MM = 100005;
int N, M, w[MM], dq[MM], dp[MM], head=0, tail=0, ans = 1e9;
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin>>w[i];
    for(int i=1;i<=N;i++){
        while(tail>=head&&dp[i-1]<=dp[dq[tail]]) tail--;
        dq[++tail] = i-1;
        while(tail>=head&&dq[head]<i-M) head++;
        dp[i] = w[i]+dp[dq[head]];
    }
    for(int i=N;i>N-M;i--) ans=min(dp[i], ans);
    cout << ans << endl;
    return 0;
}