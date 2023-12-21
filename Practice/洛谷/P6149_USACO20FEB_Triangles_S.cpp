#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5, md = 1e9+7;
ll N, ans, ver[MM], hor[MM];
struct pt{
    int x,y,i;
} arr[MM];
bool cmp(pt a, pt b){
    if(a.x==b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp1(pt a, pt b){
    if(a.y==b.y) return a.x<b.x;
    return a.y < b.y;
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++) { cin>>arr[i].x>>arr[i].y; arr[i].i = i;}
    sort(arr, arr+N, cmp);
    int i=0, j=0;
    while(i<N){
        while(arr[j].x==arr[i].x) j++;
        int cnt=0;
        for(int k=i;k<j;k++){
            cnt+=arr[k].y-arr[i].y;
        }
        ver[arr[i].i]=cnt;
        for(int k=i+1;k<j;k++){
            cnt-=(j-k-1)*(arr[k].y-arr[k-1].y);
            cnt+=(k-i-1)*(arr[k].y-arr[k-1].y);
            ver[arr[k].i]=cnt;
        }
        i=j;
    }
    // for(int i=0;i<N;i++) cout << ver[i] << " ";
    sort(arr, arr+N, cmp1);
    i=0, j=0;
    while(i<N){
        while(arr[j].y==arr[i].y) j++;
        int cnt=0;
        for(int k=i;k<j;k++){
            cnt+=arr[k].x-arr[i].x;
        }
        hor[arr[i].i]=cnt;
        for(int k=i+1;k<j;k++){
            cnt-=(j-k-1)*(arr[k].x-arr[k-1].x);
            cnt+=(k-i-1)*(arr[k].x-arr[k-1].x);
            hor[arr[k].i]=cnt;
        }
        i=j;
    }
    for(int i=0;i<N;i++) ans = (ans+(ver[i]*hor[i])%md)%md;
    cout << ans << endl;
    return 0;
}