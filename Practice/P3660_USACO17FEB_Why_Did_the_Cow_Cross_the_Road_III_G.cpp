#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+5;
int N, t[2*MM], ans=0;
pair<int, int> p[MM];
int lowbit(int x){return x&-x;}
int get(int a){
    int sum=0;
    while(a>0){
        sum+=t[a];
        a-=lowbit(a);
    }
    return sum;
}
void upt(int i, int x){
    while(i<=2*N){
        t[i]+=x;
        i+=lowbit(i);
    }
}
int main(){
    cin >> N;
    for(int i=1, a;i<=2*N;i++){
        cin >> a;
        if(p[a].first!=0) p[a].second=i;
        else p[a].first=i;
    }
    sort(p+1, p+N+1);
    for(int i=1;i<=N;i++){
        ans+=get(p[i].second)-get(p[i].first);
        upt(p[i].second, 1);
    }
    cout << ans << endl;
    return 0;
}