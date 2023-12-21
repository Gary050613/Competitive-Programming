#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
struct pt{
    int p;
    int t = -1;//-1: cow
    int r = 1e9+5;
} arr[2*MM];
int K, M, N, sum=0, ans=0;
priority_queue<int> pq;
bool cmp(pt a, pt b){return a.p < b.p;}
int main(){
    cin >> K >> M >> N;
    for(int i=1;i<=K;i++) cin >> arr[i].p >> arr[i].t;
    for(int i=K+1;i<=K+M;i++) cin >> arr[i].p;
    sort(arr+1, arr+K+M+1, cmp);
    int last = 0;
    for(int i=1;i<=K+M;i++){
        // cout << arr[i].p << " " << arr[i].t << " " << arr[i].r << endl;
        if(arr[i].t == -1) last = i;
        else if(last == 0) continue;
        else{
            arr[i].r = min(arr[i].r, arr[i].p-arr[last].p);
        }
    }
    last = 0;
    for(int i=K+M;i>=1;i--){
        if(arr[i].t == -1) last = i;
        else if(last == 0) continue;
        else{
            arr[i].r = min(arr[i].r, arr[last].p-arr[i].p);
        }
    }
    // for(int i=1;i<=K+M;i++) if(arr[i].t!=-1) cout << arr[i].r << endl;
    int i=1;
    while(arr[i].t==-1) i++;
    int j=i;
    int cur = 0, ttl = 0;
    while(j<=K+M){
        if(arr[j].t==-1) {
            pq.push(sum);
            pq.push(ttl-sum);
            // cout << i << " " << j << endl;
            i = j+1, cur=0, sum=0, ttl=0, j++;
            continue;
        }
        cur += arr[j].t;
        ttl += arr[j].t;
        while (arr[i].p+arr[i].r <= arr[j].p-arr[j].r){
            cur -= arr[i].t;
            i++;
        }
        sum = max(sum,cur);
        j++;
    }
    pq.push(ttl);
    while(N--){
        // cout << pq.top() << endl;
        ans+=pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}