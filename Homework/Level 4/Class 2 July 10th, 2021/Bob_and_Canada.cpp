#include <bits/stdc++.h>
using namespace std;
const int MM = 750005;
int T, n, r[MM], w[MM];
string str;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> str;
        memset(r, 0, sizeof(r));
        memset(w, 0, sizeof(w));
        // Find optimal a & b
        // 0 - a, a+1 - b, b+1 - n
        // ans = w[n]-w[b] + r[b]-r[a] + w[a];
        // ans = w[n]-w[n]+r[b] + w[a]-r[a];
        // Smallest w[a] - r[a]
        for(int i = 0;i<n;i++) if(str[i]=='R') r[i]++; else w[i]++;
        for(int i = 1;i<n;i++) r[i] += r[i-1], w[i] += w[i-1];
        // for(int i = 0;i<n;i++) cout << r[i] << " ";
        // cout << endl;
        // for(int i = 0;i<n;i++) cout << w[i] << " ";
        // cout << endl;
        int a=0, val = w[0]-r[0], ans = MM;
        for(int b = 1;b<n-1;b++){
            // cout << ans << " ";
            ans = min(ans, w[n-1]-w[b] + r[b]-r[a] + w[a]);
            if(w[b]-r[b]<val) a = b, val = w[b]-r[b];
        }
        cout << ans << endl;
    }
    return 0;
}