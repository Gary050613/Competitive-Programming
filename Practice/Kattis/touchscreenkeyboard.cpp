#include <bits/stdc++.h>
using namespace std;
int t, l; string keyboard[3]={"qwertyuiop","asdfghjkl","zxcvbnm"}, str, in;

int distance(char a, char b){
    int ax, ay, bx, by;
    for(int i = 0;i<3;i++)
        for(int j = 0;j<keyboard[i].length();j++)
            if(keyboard[i][j] == a) ax=i, ay=j;
    for(int i = 0;i<3;i++)
        for(int j = 0;j<keyboard[i].length();j++)
            if(keyboard[i][j] == b) bx=i, by=j;
    return abs(ax-bx) + abs(ay-by);
}

struct word{string text; int dis;} w[11];

bool cmp(word w1, word w2){
    if(w1.dis != w2.dis) return w1.dis < w2.dis;
    else return w1.text < w2.text;
}

int main(){
    cin >> t;
    while(t--){
        cin >> str >> l;
        for(int k = 0;k<l;k++){
            cin >> in; int ans = 0;
            for(int i = 0;i<str.length();i++){
                ans += distance(str[i], in[i]);
            }
            w[k].dis = ans;
            w[k].text = in;
        }
        sort(w, w+l, cmp);
        for(int i = 0;i<l;i++) cout << w[i].text << " " << w[i].dis << "\n";
    }
    return 0;
}