#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 205;
int n, m, k, K[101], ans=0, cur=0;
pii food[MM];
bool cmp(pii a, pii b){return a.first > b.first;}
int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++) cin>>K[i];
    for(int i=0;i<n;i++) cin>>food[i].first>>food[i].second;
    sort(food,food+n,cmp);
    while(cur<n&&m>0){
        // int amount = min(K[food[cur].second], m);
        // K[food[cur].second]-=amount;
        // ans+=food[cur].first * amount;
        // m-=amount;
        if(K[food[cur].second]){K[food[cur].second]--, ans+=food[cur].first, m--;}
        cur++;
    }
    cout << ans << endl;
    return 0;
}