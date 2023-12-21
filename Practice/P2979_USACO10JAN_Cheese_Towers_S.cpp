#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, T, K, dp[1255][2];
pii arr[105];
int main(){
    cin >> N >> T >> K;
    for(int i=1;i<=N;i++) cin>>arr[i].second>>arr[i].first;
    // dp[0][0]=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=(int)ceil(T*5/4);j++){
            if(j>=arr[i].first) dp[j][0] = max(dp[j][0], dp[j-arr[i].first][0]+arr[i].second);
        }
        // for(int j=0;j<=T;j++) cout << dp[j] << " ";
        // cout << endl;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=T;j++){
            if(arr[i].first>=K&&j>=arr[i].first){
                dp[j][1] = max(dp[j][1], dp[j][0]);
                dp[j][1] = max(dp[j][1], dp[(j-arr[i].first)*5/4][0]+arr[i].second);
            }else dp[j][1] = max(dp[j][0], dp[j][1]);
        }
    }
    cout << dp[T][1] << endl;
    return 0;
}