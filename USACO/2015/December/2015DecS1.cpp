#include <bits/stdc++.h>
using namespace std;

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

typedef pair<int, int> ii;
const int MM = 105;
int N, M, ans=1;
bool visited[MM][MM]={0}, light[MM][MM]={0};
vector<ii> control[MM][MM];
void dfs(int x, int y){
    if(visited[x][y]) return;
    // if(light[x][y]) ans++;
    visited[x][y]=1;
    if(control[x][y].size()>0){
        for(int i = 0;i<control[x][y].size();i++) {
            int dx=control[x][y][i].first, dy=control[x][y][i].second;
            if(light[dx][dy]==0) ans++;
            light[dx][dy]=1;
            if(visited[dx-1][dy] || visited[dx+1][dy] || visited[dx][dy-1] || visited[dx][dy+1]) dfs(dx, dy);
        }
    }
    if(x-1>=1&&light[x-1][y]) dfs(x-1, y);
    if(y-1>=1&&light[x][y-1]) dfs(x, y-1);
    if(x+1<=N&&light[x+1][y]) dfs(x+1, y);
    if(y+1<=N&&light[x][y+1]) dfs(x, y+1);
}
int main(){
    setIO("lightson");
    cin >> N >> M;
    for(int i = 0, a, b, c, d;i<M;i++){
        cin >> a >> b >> c >> d;
        control[a][b].push_back({c, d});
    }
    light[1][1]=1;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}