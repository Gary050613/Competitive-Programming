#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
int N, x=1000, y=1000, ans=0;
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};
char ch;
bool g[MM][MM]={0}, vis[MM][MM];s
int main(){
    cin >> N;
    g[x][y]=1;
    for(int i=0;i<N;i++){
        cin >> ch;
        if(ch=='N'){
            y++;
        }else if(ch=='S'){
            y--;
        }else if(ch=='E'){
            x++;
        }else if(ch=='W'){
            x--;
        }
        if(g[x][y]&&!vis[x][y]){vis[x][y]=1;ans++;}
        g[x][y]=1;
    }
    // for(int i=0;i<MM;i++){
    //     for(int j=0;j<MM;j++){
    //         if(!g[i][j]) {fill(i, j); ans++;}
    //     }
    // }
    // for(int i=0;i<55;i++){
    //     for(int j=0;j<55;j++){
    //         cout << g[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}