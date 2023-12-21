#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 1005;
int N, K, a=0, l;
priority_queue<int> pq;
bool cmp(int a, int b){return a>b;}
int check(int mid, priority_queue<int> pq){
    // mid = min per bucket
    int ans = 0, c = 0, b = 0;
    while(!pq.empty() && c<K/2 && pq.top()>mid){
        int rem = pq.top(); pq.pop();
        rem -= mid; pq.push(rem); c++;
    }
    if(c < K/2) return 0;
    while(!pq.empty() && b<K/2){
        if(pq.top()>mid){int rem = pq.top(); pq.pop(); rem-=mid; ans+=mid; pq.push(rem); b++;}
        else{ans+= pq.top(); pq.pop(); b++;}
    }
    return ans;
}
int main(){
    setIO("berries");
    cin >> N >> K;
    for(int i = 0;i<N;i++) {cin >> l; pq.push(l);}
    int l = 1, r = 1000;
    for(int i = 1;i<=1000;i++){
        a = max(a, check(i, pq));
    }
    // while(l<r){
    //     int mid = (l+r+1)/2;
    //     if(check(mid, pq)) l = mid;
    //     else r = mid-1;
    // }
    // cout << l << endl;
    // cout << check(l, pq) << endl;
    // cout << check(4, pq) << endl;
    cout << a << endl;
    return 0;
}