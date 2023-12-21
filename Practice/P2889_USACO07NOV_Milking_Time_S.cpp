#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int MM = 1e6;
int N, M, R, cur=1, dp[2*MM];
iii arr[1005];
bool cmp(iii a, iii b){
    return a.first.second < b.first.second;
}
int main(){
    cin >> N >> M >> R;
    for(int i=0;i<M;i++) cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
    sort(arr, arr+M, cmp);
    for(int i=0;i<M;i++){
        while(cur<arr[i].first.second+R){
            dp[cur] = dp[cur-1]; cur++;
        }
        dp[cur] = max(dp[arr[i].first.first]+arr[i].second, dp[cur-1]);
        cur++;
    }
    cout << dp[cur-1] << endl;
    return 0;
}