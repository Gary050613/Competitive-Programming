#include <bits/stdc++.h>
using namespace std;
int n, ans=0;
string str;
int main(){
    cin >> n;
    while(n--){
        cin >> str;
        int temp = 0;
        for(int i = 0;i<str.length();i++){
            temp+=str[i]-'0';
        }
        ans=max(ans,temp);
    }
    cout << ans << endl;
    return 0;
}