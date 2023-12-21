#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
ll N, b[MM], l[MM], r[MM], t[MM], temp[MM], ans=0;
ll lowbit(ll x){return x&-x;}
ll get(ll i){
    ll sum = 0;
    while(i>0){
        sum+=t[i];
        i-=lowbit(i);
    }
    return sum;
}
void upt(ll i, ll a){
    while(i<=N){
        t[i]+=a;
        i+=lowbit(i);
    }
}
pair<int,int> xx[MM];
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin>>b[i];
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    memset(temp, -1, sizeof(temp));
    for(int i=1;i<=N;i++){
        if(temp[b[i]]==-1) temp[b[i]] = i;
        else {l[i]=temp[b[i]]+1, r[temp[b[i]]]=i-1, temp[b[i]] = i;}
    }
    for(int i=1;i<=N;i++){
        if(l[i]==-1) l[i]=1;
        if(r[i]==-1) r[i]=N;
    }

    for (int i=1;i<=N;i++){
        xx[i] = make_pair(l[i], i);
    }
    sort(xx+1,xx+N+1);
    int j = 1;
    for(int i=1;i<=N;i++){
        //i being the left leader, how many right leaders could pair with i
        //activate all right leaders who could reach i's left side
        while (j<=N&&i>=xx[j].first){
            upt(xx[j].second, 1);
            j++;
        }
        //Query (i,l[i])
        ans += get(r[i]) - get(i);
    }
    cout << ans << endl;
    return 0;
}