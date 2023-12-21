#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 1005;
int N, maxA=0, minP=0;
bool v[MM][MM];
char g[MM][MM];
queue<pair<int, int> > q;
int dirx[4]={-1, 0, 1, 0};
int diry[4]={0, -1, 0, 1};
int main(){
    setIO("perimeter");
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>g[i][j];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(g[i][j]=='#'&&!v[i][j]){
                // bfs
                int area=0, peri=0;
                q.push({i, j});
                while(!q.empty()){
                    if(v[q.front().first][q.front().second]){q.pop(); continue;}
                    area++;
                    v[q.front().first][q.front().second]=1;
                    for(int i=0;i<4;i++){
                        int dx = q.front().first+dirx[i], dy = q.front().second+diry[i];
                        if(v[dx][dy]) continue;
                        if(g[dx][dy]=='#') q.push({dx, dy});
                        else peri++;
                    }
                    // cout << "Popping " << q.front().first << " " << q.front().second << endl;
                    q.pop();
                }
                // cout << area << " " << peri << endl;
                if(area>maxA) maxA=area, minP=peri;
                else if(area==maxA) minP=min(minP, peri);
            }
        }
    }
    cout << maxA << " " << minP << endl;
    return 0;
}