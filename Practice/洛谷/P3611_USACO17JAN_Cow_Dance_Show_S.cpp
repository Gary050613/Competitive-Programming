#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, T, d[MM];
int getT(int K){
    int cur=K, T=0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0;i<K;i++) pq.push(d[i]);
    while(cur<N){ // n
        // sort(arr, arr+K); // n log n
        // arr[0]+=d[cur++];
        int a = pq.top();
        a += d[cur++];
        pq.pop();
        pq.push(a);
        // int mi = INT_MAX, a;
        // for(int i=0;i<K;i++) if(mi>arr[i]) mi=arr[i], a=i;
        // arr[a]+=d[cur++];
    }// n * n log n
    // for(int i = 0;i<K;i++) T=max(T, arr[i]);
    while(!pq.empty()) {T=max(T,pq.top()); pq.pop();}
    return T;
}
int main(){
    cin >> N >> T;
    for(int i=0;i<N;i++) cin>>d[i];
    int l = 1, r = N;
    while(l<r){ // log n
        int mid = (l+r)/2;
        if(getT(mid)>T) l=mid+1;
        else r=mid;
    }
    cout << l << endl;
    return 0;
}