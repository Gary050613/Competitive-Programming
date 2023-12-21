#include <bits/stdc++.h>
using namespace std;
const int MM = 15;
int n, s[MM], b[MM], ans=INT_MAX;
void dfs(int x, int y, int m){
    if(m>=n) return;
    for(int i = m+1;i<n;i++){
        ans = min(ans, abs(x*s[i] - (y+b[i])));
        dfs(x*s[i], y+b[i], i);
    }
}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++) cin >> s[i] >> b[i];
    dfs(1, 0, -1);
    cout << ans << endl;
    return 0;
}