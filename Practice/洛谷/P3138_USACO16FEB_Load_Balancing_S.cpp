#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int N, pre=0, szh=0, szv=0, psa[MM][MM], ans=INT_MAX;
pair<int, int> arr[MM];
bool cmp(pair<int, int> a, pair<int, int> b){return a.second<b.second;}
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr, arr+N);
    for(int i=0;i<N;i++){
        if(arr[i].first!=pre) pre=arr[i].first, szh++;
        arr[i].first=szh;
    }
    pre=0;
    sort(arr, arr+N, cmp);
    for(int i=0;i<N;i++){
        if(arr[i].second!=pre) pre=arr[i].second, szv++;
        arr[i].second=szv;
        psa[arr[i].first][arr[i].second]=1;
    }
    for(int i=1;i<=szh;i++){
        for(int j=1;j<=szv;j++){
            psa[i][j] = psa[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    for(int i=1;i<=szh;i++){
        for(int j=1;j<=szv;j++){
            int M = 0;
            M = max(M, psa[i][j]);
            M = max(M, psa[szh][j]-psa[i][j]);
            M = max(M, psa[i][szv]-psa[i][j]);
            M = max(M, psa[szh][szv]-psa[szh][j]-psa[i][szv]+psa[i][j]);
            ans=min(ans, M);
        }
    }
    cout << ans << endl;
    return 0;
}