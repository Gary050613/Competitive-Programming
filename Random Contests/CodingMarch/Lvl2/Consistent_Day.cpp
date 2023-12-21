#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 23;
ll ans=0, cnt=1, temp[MM], arr[MM];
int N;
ll leng(int x){
    if(x<10) return 1;
    return 1+leng(x/10);
}
ll mk(int a, int x){
    ll ans=0;
    for(int i=0;i<x;i++){
        ans+=a*(int)pow(10, i);
    }
    return ans;
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    for(int k=1;k<=9;k++){
        for(int i=0;i<N;i++){
            ll length = leng(arr[i]);
            if(mk(k, length)<arr[i]) temp[i]=length;
            else temp[i]=length-1;
            // cout << i << " " << temp[i] << endl;
        }
        for(int i=0;i<N;i++) cnt*=temp[i];
        ans+=cnt;
        cnt=1;
    }
    cout << ans+1 << endl;
    return 0;
}