#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6+5;

int cnt[30];
int flag = -1, l, r;
char ans[MM];
string str;

int main(){
    cin >> str;
    for (int i = 0;i<str.length();i++) {
        cnt[str[i]-'A']++;
    }
    for (int i = 0;i<26;i++) {
        if (flag == -1 && cnt[i] % 2 == 1) {flag = i;}
        else if (flag != -1 && cnt[i] % 2 == 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    l = 0, r = str.length()-1;
    for (int i = 0;i<26;i++) {
        if (i == flag) {
            ans[str.length()/2] = 'A'+i;
            cnt[i]--;
        }
        while (cnt[i]) {
            ans[l++] = 'A'+i;
            ans[r--] = 'A'+i;
            cnt[i] -= 2;
        }
    }
    cout << ans << endl;
    return 0;
}