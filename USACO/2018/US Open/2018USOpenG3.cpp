#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 250005;
int N, W, w[255], t[255], dp[MM], ans;
int main(){
    setIO("talent");
    cin >> N >> W;
    for(int i=0;i<N;i++) cin>>w[i]>>t[i];
    for(int i=1;i<MM;i++) dp[i] = 1000000000;
    for(int i=0;i<N;i++){
        for(int j=MM-1;j>=t[i];j--){
            dp[j] = min(dp[j], dp[j-t[i]]+w[i]);
        }
    }
    for(int i=1;i<MM;i++){
        if(dp[i]>=W){
            ans = max(ans, (int)((double)(i*1000))/dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}