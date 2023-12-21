#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2505;
ll ans=1;
int N, psa[MM][MM], g[MM][MM];
pair<int, int> arr[MM];
bool cmp(pair<int, int> a, pair<int, int> b){return a.second<b.second;}
int main(){
    cin >> N;
    // 通过离散 可以使用PSA
    for(int i=1;i<=N;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr+1, arr+N+1);
    for(int i=1;i<=N;i++) arr[i].first=i;
    sort(arr+1, arr+N+1, cmp);
    for(int i=1;i<=N;i++) arr[i].second=i;
    for(int i=1;i<=N;i++) psa[arr[i].first][arr[i].second]=1;
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++) cout << psa[i][j] << " ";
    //     cout << endl;
    // }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            psa[i][j]=psa[i][j]+psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++) cout << psa[i][j] << " ";
    //     cout << endl;
    // }
    for(int i=1;i<=N;i++){
        // ans++;
        for(int j=i;j<=N;j++){
            // cout << i << " " << j << endl;
            int l = min(arr[i].first, arr[j].first), r = max(arr[i].first, arr[j].first);
            int t = min(arr[i].second, arr[j].second), b = max(arr[i].second, arr[j].second);
            // cout << l << " " << r << " " << t << " " << b << endl;
            ans+=(ll)(psa[r][t]-psa[l-1][t])*(psa[r][N]-psa[l-1][N]-psa[r][b-1]+psa[l-1][b-1]);
            // cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}