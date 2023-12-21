#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MM = 205;
int N, g[MM][MM], dij[MM];
bool v[MM];
struct priority
{
    int dis;
    int id;
    bool operator <(const priority &x)const
    {
        return x.dis<dis;
    }
};
priority_queue<priority> pq; 
int main(){
    cin >> N;
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            cin >> g[i][j];
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++) cout << g[i][j] << " ";
    //     cout << endl;
    // }
    pq.push((priority){0, 1});
    while(!pq.empty()){
        int cur = pq.top().id;
        int tmp = pq.top().dis;
        pq.pop();
        if(!v[cur]){
            v[cur] = 1;
            dij[cur] = tmp;
            for(int i=cur+1;i<=N;i++){
                pq.push((priority){dij[cur]+g[cur][i], i});
            }
        }
    }
    cout << dij[N] << endl;
    return 0;
}