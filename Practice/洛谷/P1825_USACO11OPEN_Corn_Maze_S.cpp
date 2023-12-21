#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MM = 305;
int N, M, x, y, ans;
pair<int, int> portal[MM][MM], arr[30];
bool visited[MM][MM];
char g[MM][MM];
queue<pair< ii, int> > q;
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>g[i][j];
            if(g[i][j]=='@') x=i,y=j;
            if(g[i][j]>='A'&&g[i][j]<='Z'){
                if(arr[g[i][j]-'A'].first==0&&arr[g[i][j]-'A'].second==0){
                    arr[g[i][j]-'A']={i, j};
                }else{
                    portal[arr[g[i][j]-'A'].first][arr[g[i][j]-'A'].second] = {i, j};
                    portal[i][j] = {arr[g[i][j]-'A'].first,arr[g[i][j]-'A'].second};
                }
            }
        }
    }
    q.push({{x, y}, 0});
    while(!q.empty()){
        int a=q.front().first.first, b=q.front().first.second;
        if(visited[a][b]) {q.pop();continue;}
        if(g[a][b]=='='){ans=q.front().second; break;}
        visited[a][b]=1;
        if(isalpha(g[a][b])) {int c=a, d=b; a=portal[c][d].first, b=portal[c][d].second;}
        if(a-1>=1&&!visited[a-1][b]&&g[a-1][b]!='#') q.push({{a-1, b}, q.front().second+1});
        if(a+1<=N&&!visited[a+1][b]&&g[a+1][b]!='#') q.push({{a+1, b}, q.front().second+1});
        if(b-1>=1&&!visited[a][b-1]&&g[a][b-1]!='#') q.push({{a, b-1}, q.front().second+1});
        if(b+1<=M&&!visited[a][b+1]&&g[a][b+1]!='#') q.push({{a, b+1}, q.front().second+1});
        q.pop();
    }
    cout << ans << endl;
    return 0;
}