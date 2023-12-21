#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll X, Y, ans=0, cntX=0, cntY=0, cnt=0;
char ch;
int main(){
    cin >> N >> X >> Y;
    for(int i=0;i<N;i++){
        cin >> ch;
        if(ch=='1') cntX++, cnt=0;
        if(ch=='0') cnt++;
        if(cnt==Y) cntY++, cnt=0;
    }
    ans = cntX*X + cntY;
    cout << ans << endl;
    return 0;
}