#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5005;
ll N, M, K, x, y, x2, y2, Q, A, B, C, D, g[MM][MM]={0};
int main(){
    cin >> N >> M >> K;
    while(K--){
        cin >> x >> y >> x2 >> y2;
        g[x][y]++, g[x][y2+1]--, g[x2+1][y]--, g[x2+1][y2+1]++;
    }
    // Convert 2d diff array to normal array
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
        }
    }
    cin >> Q;
    while(Q--){
        cin >> A >> B >> C >> D;
        cout << g[C][D] - g[A-1][D] - g[C][B-1] + g[A-1][B-1] << endl;
    }
    // for(int i = 1;i<=N;i++){
    //     for(int j = 1;j<=M;j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}