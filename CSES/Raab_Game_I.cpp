#include <bits/stdc++.h>
using namespace std;

int t, n, a, b;

int main(){
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if ((a + b) > n) {
            cout << "NO" << endl;
            continue;
        }
        if (a == 0 && b == 0) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) cout << i << " ";
            for (int i = 1; i <= n; i++) cout << i << " ";
            continue;
        }
        if (a == 0 || b == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int sum = a + b;
        for (int i = 0; i < a; i++) {
            cout << sum - i << " ";
        }
        for (int i = 0; i < b; i++) {
            cout << sum - i - a << " ";
        }
        for (int i = sum + 1; i <= n; i++) cout << i << " ";
        cout << endl;
        for (int i = 0; i < a; i++) {
            cout << sum - i - b << " ";
        }
        for (int i = 0; i < b; i++) {
            cout << sum - i << " ";
        }
        for (int i = sum + 1; i <= n; i++) cout << i << " ";
        cout << endl;
    }
    return 0;
}