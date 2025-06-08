#include <bits/stdc++.h>
using namespace std;

int n;

void fun(string out, bool l) {
    if (out.length() == n) {
        cout << out << endl;
        return;
    }
    if (l) {
        fun(out + "0", 1);
        fun(out + "1", 0);
    } else {
        fun(out + "1", 1);
        fun(out + "0", 0);
    }
}

int main(){
    cin >> n;
    fun("", 1);
    return 0;
}