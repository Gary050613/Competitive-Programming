#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, h[MM]={0}, j[MM]={0}, ans[MM]={0}, st[MM]={0}, sz=0;
int main(){
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> h[i];
    for(int i = 1;i<=N;i++) cin >> j[i];
    for(int i = N;i>=1;i--){
        while(sz>0 && h[i]>=st[sz-1]) sz--;
        if(sz-j[i]<0) ans[i]=-1;
        else ans[i] = st[sz-j[i]];
        st[sz++] = h[i];
    }
    for(int i = 1;i<=N;i++) cout << ans[i] << " ";
    return 0;
}