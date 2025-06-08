#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;

int n, arr[MM];

int main(){
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        if (n % 4 == 3) {
            cout << (n/2)+1 << endl;
            cout << "1 2";
            for (int i = 4;i<=((n-3)/4+3);i++) {
                cout << " " << i;
            }
            for (int i = ((n-3)/4*3+3)+1;i<=n;i++) {
                cout << " " << i;
            }
            cout << endl << (n/2) << endl;
            cout << "3";
            for (int i = ((n-3)/4+3)+1;i<=((n-3)/4*3+3);i++) {
                cout << " " << i;
            }
            cout << endl;
        } else {
            cout << n/2 << endl;
            for (int i = 1;i<=n/4;i++) {
                cout << i << " ";
            }
            for (int i = n/4*3+1;i<=n;i++) {
                cout << i << " ";
            }
            cout << endl << n/2 << endl;
            for (int i = n/4+1;i<=n/4*3;i++) {
                cout << i << " ";
            }
        }
    }
    return 0;
}