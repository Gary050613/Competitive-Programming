#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, M;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
ll getK(ll X){
    ll r = N, K = 0;
    while(r>0){
        ll Y = floor(r/X);
        if(Y<=M){K+=(r+M-1)/M; return K;};
        ll a = floor(r/Y+1-X);
        r-=a*Y;
        // if(Y<0) Y=0;
        K+=a;
    }
    return K;
}
ll searchX(ll l, ll r){
    if(l==r) return l;
    ll mid = (l+r+1)/2;
    if(getK(mid)>K) return searchX(l, mid-1);
    else return searchX(mid, r);
}
int main(){
    setIO("loan");
    cin >> N >> K >> M;
    // N-=K*M;
    cout << searchX(1, 1e12) << endl;
    return 0;
}
