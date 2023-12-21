#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM =  5e4+5;
int N, L, arr[MM], t[MM], ll[MM], lN=0;
double totalW=0;
struct cow{
    int w, x, d, t;
} tp[MM];

bool cmpX(cow c1, cow c2){return c1.x<c2.x;}
bool cmpT(cow c1, cow c2){return c1.t<c2.t;}
int getT(){
    int i=0, l=0, r=N-1;
    long long W = 0;
    for(i = 0;i<N;i++){
        if(arr[i] == 1){
            W+=tp[r].w;
            r--;
        }else{
            W+=tp[l].w;
            l++;
        }
        if(W >= totalW/2) break;
    }
    return t[i];
}
int getL(int L){
    int l=0, r=lN-1;
    while(l<r){
        int mid = (l+r)/2;
        if(ll[mid]>=L) r=mid;
        else l = mid+1;
    }
    if(ll[l]<L) return -1;
    return l;
}
int getR(int R){
    int l=0, r=lN-1;
    while(l<r){
        int mid = (l+r+1)/2;
        if(ll[mid]<=R) l=mid;
        else r = mid-1;
    }
    if(ll[l]>R) return -1;
    return l;
}
int getAns(int T){
    int ans = 0;
    for(int i = 0;i<N;i++){
        if(tp[i].d == -1) continue;
        int a = getR(tp[i].x+2*T);
        int b = getL(tp[i].x);
        if(a == -1 || b == -1) continue;
        ans += a - b + 1;
        // cout << getR(tp[i].x+2*T) << endl;
        // cout << getL(tp[i].x) << endl;
    }
    return ans;
}
int main(){
    // 0 ... L
    setIO("meetings");
    cin >> N >> L;
    for(int i = 0;i<N;i++){
        cin >> tp[i].w >> tp[i].x >> tp[i].d; totalW += tp[i].w;
        if(tp[i].d==1) {tp[i].t = L-tp[i].x;}
        else {tp[i].t = tp[i].x; ll[lN++]=tp[i].x;}
    }
    sort(tp, tp+N, cmpT);
    sort(ll, ll+lN);
    for(int i=0;i<N;i++) arr[i] = tp[i].d, t[i] = tp[i].t;
    sort(tp, tp+N, cmpX);
    // for(int i = 0;i<N;i++) cout << tp[i].x << " ";
    // cout << endl;
    // for(int i = 0;i<N;i++) cout << tp[i].d << " ";
    // cout << endl;
    // for(int i = 0;i<N;i++) cout << tp[i].t << " ";
    // cout << endl;
    // for(int i = 0;i<lN;i++) cout << ll[i] << " ";
    // cout << endl;
    // for(int i = 0;i<N;i++) cout << arr[i] << " ";
    // cout << endl;
    // cout << getT() << endl;
    // cout << getR(2) << endl;
    cout << getAns(getT()) << endl;
    return 0;
}