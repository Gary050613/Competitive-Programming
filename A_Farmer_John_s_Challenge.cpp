#include <bits/stdc++.h>
using namespace std;

int T, n, k;

int main(){
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (n == k) {
            cout << 1;
            for (int i = 1;i < n; i++) cout << " " << 1;
            cout << endl;
        } else if (k == 1) {
            cout << 1;
            for (int i = 1;i < n; i++) cout << " " << 2;
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}