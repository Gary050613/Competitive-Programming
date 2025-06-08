#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+5;

int n, cnt, ans[MM][2];

void move(int x, int from, int to, int mid) {
    if (x == 1) {
        ans[cnt][0] = from, ans[cnt++][1] = to;
        return;
    }
    move(x-1, from, mid, to);
    ans[cnt][0] = from, ans[cnt++][1] = to;
    move(x-1, mid, to, from);
}

int main(){
    cin >> n;
    move(n, 1, 3, 2);
    cout << cnt << endl;
    for (int i = 0;i<cnt;i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}