#include <bits/stdc++.h>
using namespace std;

int T, N, arr[55];

int main(){
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0;i < N; i++) {
            cin >> arr[i];
        }
        if (arr[0] == arr[N-1]) {
            cout << "NO" << endl;
            continue;
        } else {
            cout << "YES" << endl;
            if (arr[0] != arr[1]) {
                for (int i = 0; i < N-1; i++) {
                    cout << 'R';
                }
                cout << 'B' << endl;
            } else {
                cout << 'B';
                for (int i = 1; i < N; i++) {
                    cout << 'R';
                }
                cout << endl;
            }
        }
    }
    return 0;
}