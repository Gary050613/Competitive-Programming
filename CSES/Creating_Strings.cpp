#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+5;

int cnt[30], sz;
string ans[MM];
string input;

void f(string curWord) {
    if (curWord.length() == input.length()) {ans[sz++] = curWord; return;}
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            cnt[i]--;
            f(curWord + (char) ('a'+i));
            cnt[i]++;
        }
    }
}

int main(){
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        cnt[input[i]-'a']++;
    }
    f("");
    cout << sz << endl;
    for (int i = 0; i < sz; i++) cout << ans[i] << endl;
    return 0;
}