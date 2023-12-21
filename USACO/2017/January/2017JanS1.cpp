#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 1e4+5;
int N, T, d[MM];
int getT(int K){
    int arr[K+5]={0}, cur=K, T=0;
    for(int i = 0;i<K;i++) arr[i] = d[i];
    while(cur<N){ // n
        // sort(arr, arr+K); // n log n
        int mi = INT_MAX, a;
        for(int i=0;i<K;i++) if(mi>arr[i]) mi=arr[i], a=i;
        arr[a]+=d[cur++];
        // arr[0]+=d[cur++];
    }// n * n log n
    for(int i = 0;i<K;i++) T=max(T, arr[i]);
    return T;
}
int main(){
    setIO("cowdance");
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