#include <bits/stdc++.h>
using namespace std;
int N, Q, f[50005][20], g[50005][20];
int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> f[i][0];
        g[i][0] = f[i][0];
    }
    for(int j=1;j<=20;j++){
        for(int i=1;i+(1<<j)-1<=N;i++){
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
            g[i][j] = min(g[i][j-1], g[i+(1<<(j-1))][j-1]);
        }
    }
    int l, r, mx, mi;
    while(Q--){
        cin >> l >> r;
        int s = log2(r-l+1);
        mx = max(f[l][s], f[r-(1<<s)+1][s]);
        mi = min(g[l][s], g[r-(1<<s)+1][s]);
        cout << mx - mi << endl;
    }
    return 0;
}