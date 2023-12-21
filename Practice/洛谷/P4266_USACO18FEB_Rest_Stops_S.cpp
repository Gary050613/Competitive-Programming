#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MM = 1e5+5;
ll L, N, f, b, ans=0;
pii arr[MM];
bool cmp(pii a, pii b){
    if(a.second > b.second) return true;
    else if(a.second==b.second) return a.first > b.first;
    return false;
}
int main(){
    cin >> L >> N >> f >> b;
    for(int i = 0;i<N;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr, arr+N, cmp);
    int cur = 0;
    for(int i = 0;i<N;i++){
        if(cur>=arr[i].first) continue;
        ans += arr[i].second * (f-b) * (arr[i].first - cur);
        cur = arr[i].first;
    }
    cout << ans << endl;
    return 0;
}