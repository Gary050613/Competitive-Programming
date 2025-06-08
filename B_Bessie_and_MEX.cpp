#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

int T, n, a, curTop = 0;
bool v[MM];

int main(){
    cin >> T;
    while (T--) {
        cin >> n;
        curTop = 0;
        memset(v, 0, sizeof(v));
        while (n--) {
            cin >> a;
            if (a >= 1) {
                cout << curTop << " ";
                v[curTop] = 1;
                while (v[curTop]) curTop++;
            } else {
                cout << curTop - a << " ";
                v[curTop - a] = 1;
            }
        }
        cout << endl;
    }
    return 0;
}