#include <bits/stdc++.h>
using namespace std;
const int MM = 65540;
int N, K, arr[MM], ans=1;
priority_queue<int> pq;
bool cmp(int a, int b){return a > b;}
int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {cin>>arr[i]; arr[i]/=12;}
    sort(arr, arr+N, cmp);
    for(int i=1;i<N;i++){
        if(arr[i]==arr[i-1]) continue;
        else {pq.push(arr[i-1]-arr[i]-1); ans++;}
    }
    // cout << ans << endl;
    pq.push(arr[N-1]);
    K--;
    while(!pq.empty()&&K--) pq.pop();
    while(!pq.empty()) {ans+=pq.top(); pq.pop();}
    ans*=12;
    cout << ans << endl;
    return 0;
}