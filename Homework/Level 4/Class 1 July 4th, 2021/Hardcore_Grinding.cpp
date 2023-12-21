#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+5;
int N, s, f, diff[MM]={0}, e=0;
int main(){
    cin >> N;
    while(N--){
        cin >> s >> f;
        diff[s]++, diff[f]--;
        e = max(f, e);
    }
    int cur=0, ans=0;
    for(int i = 0;i<=e;i++){
        cur+=diff[i];
        ans=max(ans,cur);
    }
    cout << ans << endl;
    return 0;
}