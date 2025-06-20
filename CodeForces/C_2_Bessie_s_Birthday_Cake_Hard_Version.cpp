#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

int T, n, x, y, ans;
int arr[MM], odd[MM], szO, totalE;

int main(){
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        szO = 0, totalE = 0;
        for (int i = 0; i < x; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+x);
        ans = 0;
        for (int i = 0; i < x; i++) {
            if (i == 0) {
                // if (arr[i] + n - arr[x-1] == 2) ans++;
                if ((arr[i] + n - arr[x-1] - 1) % 2 == 1) {
                    odd[szO++] = arr[i] + n - arr[x-1] - 1;
                } else {
                    totalE += arr[i] + n - arr[x-1] - 1;
                }
            } else {
                // if (arr[i] - arr[i-1] == 2) ans++;
                if ((arr[i] - arr[i-1] - 1) % 2 == 1) {
                    odd[szO++] = arr[i] - arr[i-1] - 1;
                } else {
                    totalE += arr[i] - arr[i-1] - 1;
                }
            }
        }
        ans += x - 2;
        sort(odd, odd+szO);
        for (int i = 0; i < szO; i++) {
            odd[i] = odd[i]/2;
            if (y >= odd[i]) {
                y -= odd[i];
                ans += odd[i]*2+1;
            } else {
                totalE += odd[i] * 2;
            }
        }
        totalE /= 2;
        if (totalE >= y) {
            ans += y * 2;
        } else {
            ans += totalE * 2;
        }
        cout << ans << endl;
    }
    return 0;
}