#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int N, M;
char g[MM][MM];
bool v[MM][MM];
int ans[MM][MM], x, y;
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};
queue<pair<int, int> > q;
void bfs(int a, int b){
    q.push({a, b});
    v[a][b] = 1;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        if(ans[x][y] == -1){q.pop(); continue;}
        // if(g[x][y]!='.' && g[x][y]!='S'){
            // switch(g[x][y]){
            //         case 'L':
            //             if(v[x][y-1] || ans[x][y-1] == -1 || y-1<1) break;
            //             v[x][y-1] = 1;
            //             ans[x][y-1] = ans[x][y];
            //             q.push({x, y-1});
            //             break;
            //         case 'R':
            //             if(v[x][y+1] || ans[x][y+1] == -1 || y+1>M) break;
            //             v[x][y+1] = 1;
            //             ans[x][y+1] = ans[x][y];
            //             q.push({x, y+1});
            //             break;
            //         case 'U':
            //             if(v[x-1][y] || ans[x-1][y] == -1 || x-1<1) break;
            //             v[x-1][y] = 1;
            //             ans[x-1][y] = ans[x][y];
            //             q.push({x-1, y});
            //             break;
            //         case 'D':
            //             if(v[x+1][y] || ans[x+1][y] == -1 || x+1>N) break;
            //             v[x+1][y] = 1;
            //             ans[x+1][y] = ans[x][y];
            //             q.push({x+1, y});
            //             break;
            // }
        // }else{
            for(int i=0;i<4;i++){
                int dx = x + dirx[i]; int dy = y + diry[i];
                if(dx > N || dx < 1 || dy > M || dy < 1) continue;
                if(ans[dx][dy] == -1) continue;
                if(v[dx][dy]) continue;
                v[dx][dy]=1;
                bool flag = 1;
                while(g[dx][dy]!='.'){
                    switch(g[dx][dy]){
                        case 'L':
                            dy--;
                            break;
                        case 'R':
                            dy++;
                            break;
                        case 'U':
                            dx--;
                            break;
                        case 'D':
                            dx++;
                            break;
                    }
                    if(v[dx][dy] || ans[dx][dy] == -1 || dx > N || dx < 1 || dy > M || dy < 1) {flag = 0; break;}
                    v[dx][dy] = 1;
                }
                if(flag){
                    ans[dx][dy] = ans[x][y]+1;
                    q.push({dx, dy});
                }
            }
        // }
        q.pop();
    }
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> g[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(g[i][j]=='S') x=i, y=j;
            if(g[i][j]=='C'){
                ans[i][j] = -1;
                for(int k=0;k<4;k++){
                    int dx = i+dirx[k]; int dy = j+diry[k];
                    // if(g[dx][dy] == '.' || g[dx][dy] == 'S') ans[dx][dy] = -1;
                    // else if(g[dx][dy] != 'C' && g[dx][dy] != 'W'){
                    //     int cx = dx + dirx[k]; int cy = dy+diry[k];
                        while(g[dx][dy] != 'W' && dx >= 1 && dx <= N && dy >= 1 && dy <= M){
                            if(g[dx][dy] == '.' || g[dx][dy] == 'S') ans[dx][dy] = -1;
                            dx += dirx[k];
                            dy += diry[k];
                        }
                        // if(g[cx][cy] == '.' || g[dx][dy] == 'S') ans[cx][cy] = -1;
                }
            }
            if(g[i][j]=='W') ans[i][j] = -1;
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++) cout << ans[i][j] << " ";
    //     cout << endl;
    // }
    bfs(x, y);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(g[i][j] == '.' && ans[i][j]) cout << ans[i][j] << endl;
            else if(g[i][j] == '.' && !ans[i][j]) cout << -1 << endl;
        }
    }
    return 0;
}