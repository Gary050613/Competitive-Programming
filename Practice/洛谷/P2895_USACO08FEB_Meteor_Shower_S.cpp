#include <bits/stdc++.h>
using namespace std;
const int MM = 310;
int M, ans=-1;
int dirx[4]={1, 0, -1, 0};
int diry[4]={0, 1, 0, -1};
bool g[MM][MM], v[MM][MM], res[MM][MM];
pair<int, pair<int, int> > arr[50005];
queue<pair<int, pair<int, int> > > q;
int main(){
    cin >> M;
    for(int i=0, a, x, y;i<M;i++){
        cin >> x >> y >> a;
        arr[i]={a, {x, y}};
        res[x][y]=1;
        for(int j=0;j<4;j++){
            int dx=x+dirx[j], dy=y+diry[j];
            if(dx<0||dy<0) continue;
            res[dx][dy]=1;
        }
    }
    sort(arr, arr+M);
    q.push({0, {0, 0}});
    v[0][0]=1;
    int cnt = 0;
    // for(int i=0;i<6;i++){
    //     for(int j=0;j<6;j++)
    //         cout << res[i][j] << " ";
    //     cout << endl;
    // }
    while(!q.empty()){
        if(!res[q.front().second.first][q.front().second.second]) {ans=q.front().first; break;}
        while(arr[cnt].first<=q.front().first){
            for(int j=0;j<4;j++){
                int dx=arr[cnt].second.first+dirx[j], dy=arr[cnt].second.second+diry[j];
                if(dx<0||dy<0) continue;
                g[dx][dy]=1;
            }
            cnt++;
        }
        if(g[q.front().second.first][q.front().second.second]){q.pop(); continue;}
        for(int i=0;i<4;i++){
            int dx=q.front().second.first+dirx[i], dy=q.front().second.second+diry[i];
            if(dx<0||dy<0||g[dx][dy]||v[dx][dy]) continue;
            v[dx][dy]=1;
            q.push({q.front().first+1, {dx, dy}});
        }
        q.pop();
    }
    cout << ans << endl;
    return 0;
}