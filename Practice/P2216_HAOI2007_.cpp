// #include <bits/stdc++.h>
#include <iostream>
#include <deque>
using namespace std;
const int MM = 1005;
int a, b, n, g[MM][MM], mx[MM][MM], mi[MM][MM], ans=1e9+5;
deque<int> que;
int main(){
    cin >> a >> b >> n;
    if(n==1){cout << 0; return 0;}
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++) cin>>g[i][j];
    }
    // max init
    for(int i=1;i<=a;i++){
        for(int j=1;j<=n-1;j++){
            while(!que.empty()&&g[i][que.back()]<=g[i][j]) que.pop_back();
            que.push_back(j);
        }
        for(int j=n;j<=b;j++){
            while(!que.empty()&&que.front()<j-n+1) que.pop_front();
            while(!que.empty()&&g[i][que.back()]<=g[i][j]) que.pop_back();
            que.push_back(j);
            mx[i][j-n+1] = g[i][que.front()];
        }
        que.clear();
    }
    for(int j=1;j<=b-n+1;j++){
        for(int i=1;i<=n-1;i++){
            while(!que.empty()&&mx[que.back()][j]<=mx[i][j]) que.pop_back();
            que.push_back(i);
        }
        for(int i=n;i<=a;i++){
            while(!que.empty()&&que.front()<i-n+1) que.pop_front();
            while(!que.empty()&&mx[que.back()][j]<=mx[i][j]) que.pop_back();
            que.push_back(i);
            mx[i-n+1][j] = mx[que.front()][j];
        }
        que.clear();
    }
    // mi init
    for(int i=1;i<=a;i++){
        for(int j=1;j<=n-1;j++){
            while(!que.empty()&&g[i][que.back()]>=g[i][j]) que.pop_back();
            que.push_back(j);
        }
        for(int j=n;j<=b;j++){
            while(!que.empty()&&que.front()<j-n+1) que.pop_front();
            while(!que.empty()&&g[i][que.back()]>=g[i][j]) que.pop_back();
            que.push_back(j);
            mi[i][j-n+1] = g[i][que.front()];
        }
        que.clear();
    }
    for(int j=1;j<=b-n+1;j++){
        for(int i=1;i<=n-1;i++){
            while(!que.empty()&&mi[que.back()][j]>=mi[i][j]) que.pop_back();
            que.push_back(i);
        }
        for(int i=n;i<=a;i++){
            while(!que.empty()&&que.front()<i-n+1) que.pop_front();
            while(!que.empty()&&mi[que.back()][j]>=mi[i][j]) que.pop_back();
            que.push_back(i);
            mi[i-n+1][j] = mi[que.front()][j];
        }
        que.clear();
    }
    for(int i=1;i<=a-n+1;i++){
        for(int j=1;j<=b-n+1;j++) ans=min(ans, mx[i][j]-mi[i][j]);
    }
    cout << ans << endl;
    return 0;
}