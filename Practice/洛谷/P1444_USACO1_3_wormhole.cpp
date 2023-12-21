#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define x first
#define y second
const int MM = 15;
int N, ans, in[MM], out[MM];
bool v[MM];
ii arr[MM];
bool cmp(ii a, ii b){
    if(a.y==b.y) return a.x<b.x;
    else return a.y<b.y;
}
bool search(int u){
    if(v[u]) {return true;}
    v[u]=1;
    if(out[in[u]]) return search(out[in[u]]);
    return false;
}
void make(int u, int cnt){
    if(cnt==N/2){
        // for(int i=1;i<=N;i++) cout<<in[i]<<" ";
        // cout << endl;
        for(int i=1;i<=N;i++){
            memset(v, 0, sizeof(v));
            if(search(i)){ans++; break;}
        }
        return;
    }
    for(int i=u+1;i<=N;i++){
        if(in[i]) continue;
        in[u]=i, in[i]=u;
        if(cnt==N/2-1) make(0, cnt+1);
        for(int j=1;j<=N;j++){
            if(!in[j]) {make(j, cnt+1);break;}
        }
        in[u]=0, in[i]=0;
    }
}
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin>>arr[i].x>>arr[i].y;
    sort(arr+1, arr+1+N, cmp);
    for(int i=1;i<=N-1;i++){
        if(arr[i].y==arr[i+1].y) {out[i]=(i+1);}
    }
    // for(int i=1;i<=N;i++) cout<<arr[i].x<<" "<<arr[i].y<<endl;
    // for(int i=1;i<=N;i++) cout<<out[i]<<" ";
    make(1, 0);
    cout << ans << endl;
    return 0;
}