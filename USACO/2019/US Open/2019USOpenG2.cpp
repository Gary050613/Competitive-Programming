#include <bits/stdc++.h>
using namespace std;
const int MM = 7505;
typedef long long ll;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int N, K, cnt=0;
bool v[MM];
ll arr[MM], dis[MM];
bool cmp(ll a, ll b){return a>b;}
struct priority{
    ll dis;
    int to;
    bool operator <(const priority &x)const{
        return dis>x.dis;
    }
};
priority_queue<priority> pq;
int main(){
    setIO("walk");
    cin >> N >> K;
    v[1]=1;
    ll a = 2019201913, b = 2019201949, c = 2019201997;
    for(int j=2;j<=N;j++){
        pq.push((priority){((a*1+b*j)%c), j});
        dis[j] = (a*1+b*j)%c;
    }
    // while(!pq.empty()){cout << pq.top().dis << endl; pq.pop();}
    while(!pq.empty()&&cnt < N){
        if(!v[pq.top().to]){
            v[pq.top().to]=1;
            arr[cnt++] = pq.top().dis;
            ll cur = pq.top().to;
            // cout << pq.top().dis << endl;
            pq.pop();
            for(int j=1;j<=N;j++){
                if(j==cur||v[j]) continue;
                if(j > cur) {
                    if(dis[j]>(a*cur+b*j)%c){
                        dis[j] = (a*cur+b*j)%c;
                        pq.push((priority){((a*cur+b*j)%c), j}); /*cout << (a*pq.top().to+b*j)%c << endl;*/
                    }
                }
                else {
                    if(dis[j]>(a*j+b*cur)%c){
                        dis[j] = (a*j+b*cur)%c;
                        pq.push((priority){((a*j+b*cur)%c), j}); /*cout << (a*j+b*pq.top().to)%c << endl;*/
                    }
                }
            }
        }
        else pq.pop();
    }
    sort(arr, arr+cnt, cmp);
    cout << arr[K-2] << endl;
    return 0;
}