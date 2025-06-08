#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
ll curMax, curMin, maxCnt, minCnt;
int T, N, a;

int main(){
    cin >> T;
    while (T--) {
        cin >> N;
        curMax = 0, curMin = 0, maxCnt = 1, minCnt = 1;
        while (N--) {
            cin >> a;
            curMin += a;
            curMax += a;
            if (curMax >= 0) maxCnt = maxCnt*2%MOD;
            if (curMin >= 0) minCnt = minCnt*2%MOD;
            if (abs(curMin) > abs(curMax)) {
                curMax = abs(curMin);
                maxCnt = minCnt;
            } else if (abs(curMin) == abs(curMax)) {
                if (curMin == curMax) {
                    curMax = abs(curMax);
                } else {
                    maxCnt = (maxCnt+minCnt)%MOD;
                }
            }
        }
        cout << maxCnt << endl;
    }
    return 0;
}