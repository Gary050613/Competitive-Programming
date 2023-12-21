#include <bits/stdc++.h>
using namespace std;
const int MM = 30;
int N, ans, stx, sty;
int dirx[4]={0, 1, 0, -1};
int diry[4]={1, 0, -1, 0};
char board[4][4];
bool v[MM][MM][4][4][4][4][4][4][4][4][4], won[4][4][4][4][4][4][4][4][4];
pair<char, pair<char, char> > g[MM][MM];
int charToInt(char ch){
    if(ch=='.') return 1;
    if(ch=='M') return 2;
    if(ch=='O') return 3;
}
bool finished(){
    // for(int i=1;i<=3;i++){
    //     for(int j=1;j<=3;j++)
    //         cout << board[i][j] << " ";
    //     cout << endl;}
    if(board[1][1]=='M'&&board[1][2]=='O'&&board[1][3]=='O') return 1;
    if(board[2][1]=='M'&&board[2][2]=='O'&&board[2][3]=='O') return 1;
    if(board[3][1]=='M'&&board[3][2]=='O'&&board[3][3]=='O') return 1;

    if(board[1][3]=='M'&&board[1][2]=='O'&&board[1][1]=='O') return 1;
    if(board[2][3]=='M'&&board[2][2]=='O'&&board[2][1]=='O') return 1;
    if(board[3][3]=='M'&&board[3][2]=='O'&&board[3][1]=='O') return 1;

    if(board[1][1]=='M'&&board[2][1]=='O'&&board[3][1]=='O') return 1;
    if(board[1][2]=='M'&&board[2][2]=='O'&&board[3][2]=='O') return 1;
    if(board[1][3]=='M'&&board[2][3]=='O'&&board[3][3]=='O') return 1;

    if(board[3][1]=='M'&&board[2][1]=='O'&&board[1][1]=='O') return 1;
    if(board[3][2]=='M'&&board[2][2]=='O'&&board[1][2]=='O') return 1;
    if(board[3][3]=='M'&&board[2][3]=='O'&&board[1][3]=='O') return 1;

    if(board[1][1]=='M'&&board[2][2]=='O'&&board[3][3]=='O') return 1;
    if(board[1][3]=='M'&&board[2][2]=='O'&&board[3][1]=='O') return 1;
    if(board[3][3]=='M'&&board[2][2]=='O'&&board[1][1]=='O') return 1;
    if(board[3][1]=='M'&&board[2][2]=='O'&&board[1][3]=='O') return 1;
    
    return 0;
}
void dfs(int x, int y, bool changed){
    if(changed&&finished()){
        // cout << "Finished at " << x << " " << y << endl;
        if (!won[charToInt(board[1][1])]
                [charToInt(board[1][2])]
                [charToInt(board[1][3])]
                [charToInt(board[2][1])]
                [charToInt(board[2][2])]
                [charToInt(board[2][3])]
                [charToInt(board[3][1])]
                [charToInt(board[3][2])]
                [charToInt(board[3][3])]){
                    ans++;
                    won[charToInt(board[1][1])]
                    [charToInt(board[1][2])]
                    [charToInt(board[1][3])]
                    [charToInt(board[2][1])]
                    [charToInt(board[2][2])]
                    [charToInt(board[2][3])]
                    [charToInt(board[3][1])]
                    [charToInt(board[3][2])]
                    [charToInt(board[3][3])]=1;
                }
        return;
    }
    // cout << "HI from " << x << " " << y << endl;
    for(int i=0;i<4;i++){
        int dx = x+dirx[i], dy = y+diry[i];
        if(dx<1||dx>N||dy<1||dy>N||v[dx][dy][charToInt(board[1][1])]
                    [charToInt(board[1][2])]
                    [charToInt(board[1][3])]
                    [charToInt(board[2][1])]
                    [charToInt(board[2][2])]
                    [charToInt(board[2][3])]
                    [charToInt(board[3][1])]
                    [charToInt(board[3][2])]
                    [charToInt(board[3][3])]||g[dx][dy].first=='#') continue;
        v[dx][dy][charToInt(board[1][1])]
                    [charToInt(board[1][2])]
                    [charToInt(board[1][3])]
                    [charToInt(board[2][1])]
                    [charToInt(board[2][2])]
                    [charToInt(board[2][3])]
                    [charToInt(board[3][1])]
                    [charToInt(board[3][2])]
                    [charToInt(board[3][3])]=1;
        bool flag=0;
        if(g[dx][dy].first!='.'&&board[g[dx][dy].second.first-'0'][g[dx][dy].second.second-'0']=='.') board[g[dx][dy].second.first-'0'][g[dx][dy].second.second-'0']=g[dx][dy].first, flag=1;
        dfs(dx, dy, flag);
        // v[dx][dy][charToInt(board[1][1])]
        //             [charToInt(board[1][2])]
        //             [charToInt(board[1][3])]
        //             [charToInt(board[2][1])]
        //             [charToInt(board[2][2])]
        //             [charToInt(board[2][3])]
        //             [charToInt(board[3][1])]
        //             [charToInt(board[3][2])]
        //             [charToInt(board[3][3])]=0;
        if(flag) board[g[dx][dy].second.first-'0'][g[dx][dy].second.second-'0']='.';
    }
}
int main(){
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            char a, b, c;
            cin >> a >> b >> c;
            g[i][j]={a, {b, c}};
            if(a=='B'&&b=='B'&&c=='B') stx=i, sty=j;
        }
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            board[i][j]='.';
    v[stx][sty][charToInt(board[1][1])]
                    [charToInt(board[1][2])]
                    [charToInt(board[1][3])]
                    [charToInt(board[2][1])]
                    [charToInt(board[2][2])]
                    [charToInt(board[2][3])]
                    [charToInt(board[3][1])]
                    [charToInt(board[3][2])]
                    [charToInt(board[3][3])]=1;
    dfs(stx, sty, 0);
    cout << ans << endl;
    return 0;
}