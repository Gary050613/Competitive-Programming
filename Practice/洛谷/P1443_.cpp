#include <bits/stdc++.h>
using namespace std;
const int MM = 405;
int n, m, x, y, g[MM][MM];
int dirx[8]={1, 2, 2, 1, -1, -2, -2, -1};
int diry[8]={-2, -1, 1, 2, 2, 1, -1, -2};
// bool v[MM][MM];
queue<pair<int, pair<int, int> > > q;
int main(){
    cin >> n >> m >> x >> y;
    memset(g, -1, sizeof(g));
    // v[x][y]=1;
    q.push({0, {x, y}});
    while(!q.empty()){
        if(g[q.front().second.first][q.front().second.second]!=-1) {q.pop(); continue;}
        g[q.front().second.first][q.front().second.second]=q.front().first;
        for(int i=0;i<8;i++){
            int dx = q.front().second.first+dirx[i], dy = q.front().second.second+diry[i];
            if(dx<1||dx>n||dy<1||dy>m) continue;
            q.push({q.front().first+1, {dx, dy}});
        }
        q.pop();
    }
    for(int i=1;i<=n;i++)
        {for(int j=1;j<=m;j++){
            cout << setw(5) << left << g[i][j];}
        cout << endl;}
    return 0;
}