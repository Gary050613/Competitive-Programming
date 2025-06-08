#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll curMax, curMin;
int T, N, a;

int main(){
    cin >> T;
    while (T--) {
        cin >> N;
        curMax = 0, curMin = 0;
        while (N--) {
            cin >> a;
            curMin += a;
            curMax += a;
            curMax = max(abs(curMax), abs(curMin));
        }
        cout << curMax << endl;
    }
    return 0;
}