#include <bits/stdc++.h>
using namespace std;
const int MM = 205;
typedef long long ll;
typedef unsigned long long ull;
int b, v, q, t[MM]; string ans, s[MM]; map<string, ull> mp;

ull binToDec(string bin){
    ull ans = 0;
    for(int i = 0;i<bin.length();i++){
        ans = ans*2 + bin[i] - '0';
    }
    return ans;
}

int main(){
    while(cin >> b >> v){
        mp.clear();
        for(int i = 0;i<v;i++){
            cin >> s[i] >> t[i];
        }
        for(int i = 0;i<v;i++){
            string bin="", in;
            for(int j = 0;j<t[i];j++){
                cin >> in;
                bin = bin + in;
            }
            mp[s[i]] = binToDec(bin);
        }
        cin >> q;
        while(q--){
            cin >> ans;
            if(mp.count(ans)) cout << ans << "=" << mp[ans] << endl;
            else cout << ans << "=" << endl;
        }
    }
    return 0;
}