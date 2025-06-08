#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll ans = 1, n;

int main(){
    cin >> n;
    for (ll i = 1;i<=n;i++) {
        ans = ((ans % MOD) * 2) % MOD;
    }
    cout << ans << endl;
    return 0;
}