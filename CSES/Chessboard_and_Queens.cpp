#include <bits/stdc++.h>
using namespace std;

bool blocked[10][10];
bool row[10], col[10], ldiag[20], rdiag[20];
char in;
int ans;

void fun(int x) {
    if (x == 8) {ans++; return;}
    for (int y = 0; y < 8; y++) {
        if (blocked[x][y]) continue;
        int lindex = y-x+8;
        int rindex = x+y;
        if (row[x] || col[y] || ldiag[lindex] || rdiag[rindex]) continue;
        row[x] = 1, col[y] = 1, ldiag[lindex] = 1, rdiag[rindex] = 1;
        fun(x+1);
        row[x] = 0, col[y] = 0, ldiag[lindex] = 0, rdiag[rindex] = 0;
    }
}

int main(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> in;
            if (in == '*') blocked[i][j] = 1;
        }
    }
    fun(0);
    cout << ans << endl;
    return 0;
}