#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 1e5+5;
int N, q[MM], ans=0;
bool cmp(int a, int b){return a>b;}
int main(){
    setIO("lemonade");
    cin >> N;
    for(int i = 0;i<N;i++) cin >> q[i];
    sort(q,q+N,cmp);
    for(int i = 0;i<N;i++){
        if(q[i]>=ans) ans++;
    }
    cout << ans << endl;
    return 0;
}