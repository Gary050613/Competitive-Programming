#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+5;
int N, K, arr[MM], ans, m[MM], mx[MM], temp;
int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr, arr+N);
    // 循环选择两点，ans=max(m[i]+m[j])
    // 构建 m 数组 m = 从 m 向右最多可以选多少
    int l=0, r=0;
    while(l<N){
        while(r<N&&arr[l]+K>=arr[r]) r++;
        m[l]=r-l;
        l++;
    }
    for(int i=N-1;i>=0;i--){
        temp=max(temp, m[i]);
        mx[i]=temp;
    }
    for(int i=0;i<N;i++){
        ans = max(ans, m[i]+mx[i+m[i]]);
    }
    cout << ans << endl;
    return 0;
}