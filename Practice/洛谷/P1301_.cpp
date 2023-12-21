#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int N, M, g[MM][MM], ans=-1;
bool v[MM][MM][8];
int dirx[8]={0, 1, 0, -1, 1, 1, -1, -1};
int diry[8]={1, 0, -1, 0, 1, -1, 1, -1};
// cnt dir x y
queue<pair<pair<int, int>, pair<int, int> > > q;
int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            cin >> g[i][j];
    q.push({{0, 8}, {1, 1}});
    for(int i=0;i<8;i++) v[1][1][i]=1;
    while(!q.empty()){
        if(q.front().second.first==M&&q.front().second.second==N){ans=q.front().first.first;break;}
        // if(v[q.front().second.first][q.front().second.second]){q.pop(); continue;}
        // v[q.front().second.first][q.front().second.second]=1;
        for(int i=0;i<8;i++){
            int value=g[q.front().second.first][q.front().second.second];
            int dx=q.front().second.first+dirx[i]*value, dy=q.front().second.second+diry[i]*value;
            if(dx<1||dx>M||dy<1||dy>N||v[dx][dy][i]||q.front().first.second==i) continue;
            q.push({{q.front().first.first+1, i}, {dx, dy}});
            v[dx][dy][i]=1;
        }
        q.pop();
    }
    if(ans==-1) cout << "NEVER\n";
    else cout<<ans<<endl;
    return 0;
}