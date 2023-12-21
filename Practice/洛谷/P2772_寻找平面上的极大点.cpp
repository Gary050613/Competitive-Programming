#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int N, C=0;
pair<int, int> G[MM], ans[MM];
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin>>G[i].first>>G[i].second;
    sort(G, G+N);
    int mx = 0, cur=-1;
    for(int i=N-1;i>=0;i--){
        if(cur==G[i].first) continue;
        else cur=G[i].first;
        if(G[i].second>mx){mx=G[i].second; ans[C].first=G[i].first; ans[C++].second=G[i].second;}
    }
    sort(ans, ans+C);
    for(int i = 0;i<C;i++){
        printf("(%d,%d)", ans[i].first, ans[i].second);
        if(i!=C-1) cout << ",";
    }
    return 0;
}