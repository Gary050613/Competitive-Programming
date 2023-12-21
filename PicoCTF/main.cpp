#include <bits/stdc++.h>
using namespace std;
string str = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_", ans="";
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}
int main(){
    int n;
    while(cin >> n&&n!=EOF){
        ans+=str[modInverse(n, 41)];
    }
    cout << ans << endl;
    return 0;
}