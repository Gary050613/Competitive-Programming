#include <bits/stdc++.h>
using namespace std;
const int MM = 3e4+5;
int w, n, P[MM],ans=0;
int main(){
    cin >> w >> n;
    for(int i = 0;i<n;i++)cin >> P[i];
    sort(P, P+n);
    int l=0,r=n-1;
    while(l<r){
        if(P[l]+P[r]>w) ans++, r--;
        else ans++, l++, r--;
    }
    if(l==r) ans++;
    cout << ans << endl;
    return 0;
}