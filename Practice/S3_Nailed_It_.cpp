#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
int N, L, cnt[MM], ans[2*MM], mx=0, op;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> L;
        cnt[L]++;
    }
    // for(int i=2;i<=4000;i++){
    //     for(int j=1;j<=i/2;j++){
    //         ans[i] += cnt[j] + cnt[i-j]; 
    //     }
    // }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=i;j++){
            if(i==j) ans[i+j] += cnt[i]/2;
            else ans[i+j] += min(cnt[i], cnt[j]);
        }
    }
    // for(int i=1;i<=10;i++) cout << ans[i] << " ";
    // cout << endl;
    for(int i=1;i<=4000;i++) mx = max(mx, ans[i]);
    for(int i=1;i<=4000;i++){
        if(ans[i]==mx) op++;
    }
    cout << mx << " " << op;
    return 0;
}