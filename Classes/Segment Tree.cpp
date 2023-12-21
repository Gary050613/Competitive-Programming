#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N;
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
    t[k] = max(t[k*2], t[k*2+1]);
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
        int ret = -1*INT_MAX;
        int m = l+(r-l)/2;
        if(L<=m) ret = max(ret, query(k*2, l, m, L, R));
        if(R>=m+1) ret = max(ret, query(k*2+1, m+1, r, L, R));
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
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> a[i];
    build(1, 1, N);
    uptN(1, 1, N, 3, 5);
    cout << query(1, 1, N, 4, 5) << endl;
    uptQ(1, 1, N, 7, 1, 2);
    printT();
    cout << query(1, 1, N, 2, 5) << endl;
    printT();
    return 0;
}