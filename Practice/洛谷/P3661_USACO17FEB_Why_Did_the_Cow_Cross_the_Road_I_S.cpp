#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+5;
struct cow{int a, b;} S[MM];
priority_queue<pair<int,int>, vector<pair<int,int> > > pq; //>> bitwise operation
int C, N, T[MM], ans=0;
bool cmp(cow c1, cow c2){
    if(c1.a<c2.a || (c1.a==c2.a&&c1.b<c2.b)) return true;
    return false;
}
int main(){
    cin >> C >> N;
    for(int i = 0;i<C;i++) cin >> T[i];
    for(int i = 0;i<N;i++) cin >> S[i].a >> S[i].b;
    sort(T, T+C);
    sort(S, S+N, cmp);
    // int i=0, j=0;
    int j = 0;
    for(int i = 0;i<C;i++){
        while(j<N&&S[j].a<=T[i]) {pq.push(make_pair(-1*S[j].b, S[j].a));j++;}
        while(!pq.empty()&&(pq.top().first*-1)<T[i]) pq.pop();
        if(!pq.empty()&&pq.top().second<=T[i]){ans++;pq.pop();}
    }
    cout << ans << endl;
    return 0;
}