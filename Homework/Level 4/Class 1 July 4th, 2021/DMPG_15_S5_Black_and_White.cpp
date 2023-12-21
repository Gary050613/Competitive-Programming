#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, M, x, y, w, h;
bool g[MM][MM]={0};
int main(){
    cin >> N >> M;
    while(M--){
        cin >> x >> y >> w >> h;
        g[x][y] = g[x][y]^1, g[x+w][y] = g[x+w][y]^1, g[x][y+h] = g[x][y+h]^1, g[x+w][y+h] = g[x+w][y+h]^1;
    }
    int ans = 0;
    for(int i = 0;i<N;i++){
        for(int j = 1;j<N;j++){
            g[i][j] ^= g[i][j-1];
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 1;j<N;j++){
            g[j][i] ^= g[j-1][i];
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(g[i][j]==1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}