#include <bits/stdc++.h>
using namespace std;
const int MM = 23;
int N, K, arr[MM], ans;
bool isPrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}
void dfs(int u, int sum, int cnt){
    // cout << u << " " << sum << " " << cnt << endl;
    if(cnt==K){
        if(isPrime(sum)) ans++;
        return;
    }
    if(u>=N) return;
    dfs(u+1, sum+arr[u], cnt+1);
    dfs(u+1, sum, cnt);
}
int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin>>arr[i];
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}