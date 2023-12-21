#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MM = 35;
int n, g[MM][MM], ix, iy;
// int cw=0,ccw=0;
// dir: 0N 1E 2S 3W
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};
// void search(int x, int y, int dir){
//     int dx = x+dirx[dir], dy = y+diry[dir];
//     if(dx==ix && dy==iy) return;
//     if(g[dx][dy]==1) search(dx, dy, dir);
//     else{
//         if(dir==0){
//             if(g[dx+1][dy]==1) {cw++;search(dx+1, dy, 1);}
//             else if(g[dx-1][dy]==1) {ccw++; search(dx-1, dy, 3);}
//         }else if(dir==1){
//             if(g[dx][dy+1]==1) {cw++;search(dx, dy+1, 2)}
//             else if(g[dx][dy-1]==1) {ccw++; search(dx, dy-1, 0);}
//         }else if(dir==2){
//             if(g[dx+1][dy]==1) {ccw++; search(dx+1, dy, 1);}
//             else if(g[dx-1][dy]==1) {cw++; search(dx-1, dy, 3);}
//         }else if(dir==3){
//             if(g[dx][dy+1]==1) {ccw++; search(dx, dy+1, 2);}
//             else if(g[dx][dy-1]==1) {cw++; search(dx, dy-1, 0);}
//         }
//     }
// }
void bfs(int x, int y, int from, int to){
    queue<ii> q;
    g[x][y]=to;
    q.push({x, y});
    while(!q.empty()){
        for(int i=0;i<4;i++){
            int dx = q.front().first+dirx[i], dy = q.front().second+diry[i];
            if(dx>=32||dx<0||dy>=32||dy<0) continue;
            if(g[dx][dy]==from){g[dx][dy]=to; q.push({dx, dy});}
        }
        q.pop();
    }
}
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         if(g[i][j]==1){ix=i,iy=j,i=n;break;}
    // search(ix, iy, 1);
    bfs(31, 31, 0, 3);
    // for(int i = 1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << g[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(g[i][j]==0){bfs(i, j, 0, 2);i=n;break;}
    bfs(31, 31, 3, 0);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << g[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}