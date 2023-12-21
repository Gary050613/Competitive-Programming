#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int X, Y, K, M, ans=INT_MAX;
bool visited[MM][MM][MM];
void dfs(int x, int y, int n){
    if(visited[x][y][n] || n>K) return;
    visited[x][y][n]=1;
    ans=min(ans, abs(M-(x+y)));
    dfs(X, y, n+1);
    dfs(x, Y, n+1);
    dfs(0, y, n+1);
    dfs(x, 0, n+1);
    // x->y
    if(x>(Y-y)) dfs(x-(Y-y), Y, n+1);
    else dfs(0, y+x, n+1);
    // y->x
    if(y>(X-x)) dfs(X, y-(X-x), n+1);
    else dfs(x+y, 0, n+1);
}
int main(){
    cin >> X >> Y >> K >> M;
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}