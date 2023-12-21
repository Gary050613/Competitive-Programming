/*
ID: gary0501
TASK: TASK_NAME_HERE
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int MM = 1e5+5;
ll N, M;
pll arr[MM];
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
bool cmp(pll a, pll b){
    if(a.first < b.first) return true;
    return false;
}
ll getMaxN(ll D){
    ll cur = 0, ans = 0;
    for(int i = 0;i<M;i++){
        if(cur > arr[i].second) continue;
        if(cur < arr[i].first) cur = arr[i].first;
        while(cur >= arr[i].first && cur <= arr[i].second){
            cur += D; ans++;
        }
    }
    return ans;
}
ll findMaxD(ll l, ll r){
    // cout << l << " " << r << endl;
    if(l == r) return l;
    ll mid = (l+r+1)/2;
    // cout << getMaxN(mid) << endl;
    if(getMaxN(mid)<N) return findMaxD(l, mid-1);
    else return findMaxD(mid, r);
}
int main(){
    setIO("socdist");
    cin >> N >> M;
    for(int i = 0;i<M;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+M, cmp);
    // cout << getMaxN(2) << endl;
    ll mi = 1, mx = 1e18;
    cout << findMaxD(mi, mx) << endl;
    // system("pause");
    return 0;
}
