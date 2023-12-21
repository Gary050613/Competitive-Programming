#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
ll N, arr[MM], m[MM], psa[MM]={0};
double ans[MM], mx=0;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    ll mi = INT_MAX;
    for(int i=N;i>0;i--){
        mi = min(mi, arr[i]);
        m[i]=mi;
    }
    // i...j = psa[j]-psa[i-1]
    for(int i=1;i<=N;i++) psa[i]=psa[i-1]+arr[i];
    for(int i=1;i<=N-2;i++){
        ans[i]=(double)(psa[N]-psa[i]-m[i+1])/(N-i-1);
        if(ans[i]>mx) mx=ans[i];
    }
    // for(int i=195;i<=202;i++) cout << ans[i] << " ";
    // cout << endl;
    for(int i=1;i<=N-2;i++) if(ans[i]==mx) cout << i << endl;
    return 0;
}