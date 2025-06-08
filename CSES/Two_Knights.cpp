#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 10005;

ll n, arr[MM];

int main(){
    cin >> n;
    arr[1] = 0;
    arr[2] = 6;
    arr[3] = 28;
    for (ll i = 4;i<=n;i++) {
        arr[i] = (i*i*(i*i-1))/2-2*(10*i-28)-4*(i-4)*(i-4);
    }
    for (int i = 1;i<=n;i++) {
        cout << arr[i] << endl;
    }
    return 0;
}