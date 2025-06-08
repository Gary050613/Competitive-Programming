#include <bits/stdc++.h>
using namespace std;

int a, b, n, diff;

int main(){
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a > b) {
            diff = a-b;
            a -= diff*2;
            b -= diff;
        } else {
            diff = b-a;
            a -= diff;
            b -= diff*2;
        }
        if (a >= 0 && b >= 0 && a % 3 == 0 && b % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}