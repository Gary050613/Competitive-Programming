#include <bits/stdc++.h>
using namespace std;

int ans, n;

int main(){
    cin >> n;
    for (int i = 1;pow(5, i) <= n;i++) {
        ans += n/pow(5, i);
    }
    cout << ans << endl;
    return 0;
}