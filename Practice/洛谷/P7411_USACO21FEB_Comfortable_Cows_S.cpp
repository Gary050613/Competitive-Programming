#include <bits/stdc++.h>
using namespace std;
const int MM = 3005;
int N, cnt=0;
int g[MM][MM];
bool c[MM][MM], added[MM][MM];
int dirx[4]={0, 0, 1, -1};
int diry[4]={1, -1, 0, 0};
// vector<pair<int, int> > arr[100005];
void search(int x, int y){
    if((!c[x][y]&&!added[x][y])||g[x][y]!=3) return;
    // int ax, ay;
    for(int i=0;i<4;i++){ // x, y is comfortable; need find the empty neighbor slot
        int dx = x+dirx[i], dy = y+diry[i];
        if(!c[dx][dy]&&!added[dx][dy]){
            cnt++;
            added[dx][dy]=1;
            for(int j=0;j<4;j++){
                int ax = dx+dirx[j], ay = dy+diry[j];
                g[ax][ay]++;
            }
            search(dx, dy);
            for(int j=0;j<4;j++) search(dx+dirx[j], dy+diry[j]);
            break;
        }
    }
}
int main(){
    cin >> N;
    for(int i=0, x, y;i<N;i++){
        // cnt=0;
        cin >> y >> x;
        x+=1000;
        y+=1000;
        if(added[x][y]) cnt--, added[x][y]=0, c[x][y]=1;
        else{
            c[x][y]=1; added[x][y]=0;
            for(int j=0;j<4;j++) g[x+dirx[j]][y+diry[j]]++;
            search(x, y);

            for(int j=0;j<4;j++) search(x+dirx[j], y+diry[j]);
        }
        cout << cnt << endl;
        // for(int a=998;a<1005;a++){
        //     for(int b=998;b<1005;b++){
        //         if(c[a][b]) cout << 1;
        //         else if(added[a][b]) cout << 2;
        //         else cout << 0;
        //         if(c[a][b]&&added[a][b]) cout << "ERROR\n";
        //     }
        //     cout << endl;}
    }
    return 0;
}