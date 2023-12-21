#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, dp[400], sum;
int main(){
    cin >> N;
    dp[0] = 1;
    sum = (1+N)*N/2;
    for(int i=1;i<=N;i++){
        for(int j=sum/2;j>=0;j--){
            if(j>=i) dp[j] += dp[j-i];
        }
    }
    if(sum%2==1) cout << 0 << endl;
    else cout << dp[sum/2]/2 << endl;
    return 0;
}