#include <bits/stdc++.h>
using namespace std;
int N, Q;
double arr[186740]={0}, x, y, r;
int main(){
    cin >> N >> Q;
    for(int i = 0;i<N;i++){cin >> x >> y; arr[i] = sqrt(abs(x)*abs(x) + abs(y)*abs(y));}
    sort(arr, arr+N);
    while(Q--){
        cin >> r;
        int ans = upper_bound(arr, arr+N, r)-arr;
        cout << ans << endl;
    }
    return 0;
}