#include <bits/stdc++.h>
using namespace std;
const int MM = 255;
int N, B, f[MM], s[MM], d[MM], ans=INT_MAX;
bool visited[MM][MM];
void dfs(int loc, int boot){
    if(visited[loc][boot]) return;
    visited[loc][boot]=1;
    if(loc==N-1){ans=min(ans,boot);return;}
    for(int i = 1;i<=d[boot]&&loc+i<N;i++){
        if(f[loc+i]<=s[boot]) dfs(loc+i, boot);
    }
    for(int i = boot+1;i<B;i++){
        if(s[i]>=f[loc]) dfs(loc, i);
    }
}
int main(){
    cin >> N >> B;
    for(int i=0;i<N;i++)cin>>f[i];
    for(int i=0;i<B;i++)cin>>s[i]>>d[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}