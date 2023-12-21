#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6+5;
int a[MM], t[MM], lazy[MM];
void printT(){
    int cur = 0;
    for(int i=0;i<=ceil(log2(N));i++){
        for(int j=1;j<=1<<i;j++){
            cout << t[cur+j] << " ";
        }
        cur += 1<<i;
        cout << endl;
    }
}
void pushUp(int k){
    t[k] = t[k*2] + t[k*2+1];
}
void pushDown(int k){
    lazy[k*2]+=lazy[k];
    lazy[k*2+1]+=lazy[k];
    t[k*2]+=lazy[k];
    t[k*2+1]+=lazy[k];
    a[k*2]+=lazy[k];
    a[k*2+1]+=lazy[k];
    lazy[k]=0;
}
void build(int k, int l, int r){
    if(l==r){
        t[k] = a[l];
    }else{
        int m = l+(r-l)/2;
        build(k*2, l, m);
        build(k*2+1, m+1, r);
        pushUp(k);
    }
}
int query(int k, int l, int r, int L, int R){
    if(L<=l && r<=R){
        return t[k];
    }else{
        pushDown(k);
        int ret = 0;
        int m = l+(r-l)/2;
        if(L<=m) ret += query(k*2, l, m, L, R);
        if(R>=m+1) ret += query(k*2+1, m+1, r, L, R);
        return ret;
    }
}
void uptN(int k, int l, int r, int v, int n){
    if(l==r){
        t[k] += v;
        a[l] += v;
    }else{
        int m = l+(r-l)/2;
        if(n<=m){
            uptN(k*2, l, m, v, n);
        }else if(n > m){
            uptN(k*2+1, m+1, r, v, n);
        }
        pushUp(k);
    }
}
void uptQ(int k, int l, int r, int v, int L, int R){
    if(L<=l && r<=R){
        lazy[k] += v;
        t[k] += v;
        a[k] += v;
    }else{
        pushDown(k);
        int m = l+(r-l)/2;
        if(L<=m) uptQ(k*2, l, m, v, L, R);
        if(R>=m+1) uptQ(k*2+1, m+1, r, v, L, R);
        pushUp(k);
    }
}
int N, M, Q, x, y;
int main(){
    cin >> N >> M;
    build(1, 1, N);
    while(M--){
        cin >> Q;
        if(Q==1){
            cin >> x;
            cout << query(1, 1, N, x, x) << endl;
        }else{
            cin >> x >> y;
        }
    }
    return 0;
}