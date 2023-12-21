#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, arr[MM], high[MM], mx=0, low[MM], mi=0;
int main(){
    while(cin >> arr[N++]);
    for(int i=0;i<N;i++) low[i] = INT_MAX;
    for(int i=0;i<N;i++){
        int l = 0, r = mx;
        while(l<=r){
            int mid = (l+r)/2;
            // l -> r == Big -> Small
            if(high[mid]<arr[i]) r=mid-1;
            else l = mid+1;
        }
        mx = max(mx, r+1);
        high[r+1] = max(arr[i], high[r+1]);
        l = 0, r = mi;
        while(l<=r){
            int mid = (l+r)/2;
            // l -> r == Small -> Big
            if(low[mid]!=INT_MAX&&low[mid]>=arr[i]) r=mid-1;
            else l=mid+1;
        }
        mi = max(mi, r+1);
        low[r+1] = min(low[r+1], arr[i]);
    }
    cout << mx << endl;
    cout << mi << endl;
    return 0;
}