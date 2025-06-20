#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

int T, n, x, y, ans;
int arr[MM];

int main(){
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        for (int i = 0; i < x; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+x);
        ans = 0;
        for (int i = 0; i < x; i++) {
            if (i == 0) {
                if (arr[i] + n - arr[x-1] == 2) ans++;
            } else {
                if (arr[i] - arr[i-1] == 2) ans++;
            }
        }
        ans += x - 2;
        cout << ans << endl;
    }
    return 0;
}