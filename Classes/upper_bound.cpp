#include <bits/stdc++.h>
using namespace std;
const int MM =  5;
int N, arr[MM], A;
int upper_bound(int a, int l, int r){
    if(l==r) return l;
    int mid = (l+r)/2;
    if(arr[mid]<A) return upper_bound(a, mid+1, r);
    else if(arr[mid]>=A) return upper_bound(a, l, mid);
}
int main(){
    cin >> N;
    for(int i = 0;i<N;i++) cin>>arr[i];
    sort(arr, arr+N);
    cin >> A;
    cout << upper_bound(A, 0, N-1) << endl;
    return 0;
}

// 1 2 3 4 5 
/*
   1 2 3 3 4 5
4
   3 4 5
   3 4 5
   5
*/