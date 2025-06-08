#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll x;
string s;
bool flag;

char sub1 (char ch) {
    if (ch == '0') return '9';
    else return ch-1;
}

int main(){
    cin >> T;
    while (T--) {
        cin >> x;
        s = to_string(x);
        flag = true;
        for (int i = s.length()-1; i>=0; i--) {
            if (i == s.length()-1) {
                if (s[i] == '9') {flag = false; break;}
            } else if (i == 0) {
                s[i] = sub1(s[i]);
                if (s[i] != '0') {flag = false; break;}
            } else {
                s[i] = sub1(s[i]);
                if (s[i] == '9') {flag = false; break;}
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}