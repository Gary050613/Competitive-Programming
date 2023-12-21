#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int N, M, ans;
int dirx[8]={1, 1, 1, 0, -1, -1, -1, 0};
int diry[8]={-1, 0, 1, 1, 1, 0, -1, -1};
char g[MM][MM];
bool v[MM][MM];
void fill(int x, int y){
    if(v[x][y]) return;
    v[x][y]=1;
    g[x][y]='.';
    for(int i=0;i<8;i++){
        int dx=x+dirx[i], dy=y+diry[i];
        if(dx<1||dx>N||dy<1||dy>M||v[dx][dy]||g[dx][dy]=='.') continue;
        fill(dx, dy);
    }
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>g[i][j];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(g[i][j]=='W') {fill(i, j);ans++;}
    cout << ans << endl;
    return 0;
}