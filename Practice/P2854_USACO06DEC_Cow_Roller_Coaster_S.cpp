#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
struct ln{
    int x, w, f, c;
} arr[10005];
int L, n, B, dp[MM][MM];
bool cmp(ln a, ln b){
    // if((a.x+a.w) < (b.x+b.w)) return true;
    // else if((a.x+a.w) == (b.x+b.w)){
    //     if(a.x<b.x) return true;
    //     else if(a.x==b.x) return a.c<b.c;
    // }
    // return false;
    return a.x < b.x;
}
int main(){
    cin >> L >> n >> B;
    for(int i=0, x, w, f, c;i<n;i++){
        cin >> x >> w >> f >> c;
        arr[i].x=x, arr[i].w=w, arr[i].f=f, arr[i].c=c;
    }
    sort(arr, arr+n, cmp);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<=B;i++) dp[i][0]=0;
    for(int i=0;i<n;i++){
        int x = arr[i].x+arr[i].w;
        for(int j=arr[i].c;j<=B;j++){
            // if(dp[j-1][x]==-1&&dp[j-arr[i].c][x-arr[i].w]==-1) continue;
            // dp[j][x] = max(dp[j][x], dp[j-1][x]);
            if(dp[j-arr[i].c][x-arr[i].w]!=-1)
                dp[j][x] = max(dp[j][x], dp[j-arr[i].c][x-arr[i].w]+arr[i].f);
        }
    }
    // for(int i=0;i<=B;i++){
    //     for(int j=0;j<=L;j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[B][L] << endl;
    return 0;
}