#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, p[25];

ll fun(int i, ll left, ll right) {
    if (i == n) return abs(left - right);
    return min(fun(i+1, left+p[i], right), fun(i+1, left, right+p[i]));
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << fun(0, 0, 0) << endl;
    return 0;
}