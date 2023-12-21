    #include <bits/stdc++.h>
    using namespace std;
    int h1, w1, h2, w2, dp[3][301][3][301];
    int fun(int h1, int w1, int h2, int w2){
        if(dp[h1][w1][h2][w2] != -1) return dp[h1][w1][h2][w2];
        int ret = 0;
        for(int i=1;i<h1;i++) ret |= (!fun(i, w1, h1-i, w1) | !fun(h1-i, w1, h2, w2));
        for(int i=1;i<h2;i++) ret |= (!fun(i, w2, h2-i, w2) | !fun(h1, w1, h2-i, w2));
        for(int i=1;i<w1;i++) ret |= !fun(h1, i, h1, w1-i);
        for(int i=1;i<w2;i++) ret |= !fun(h2, i, h2, w2-i);
        for(int i=1;i<=10&&i<w1;i++) ret |= !fun(h1, w1-i, h2, w2);
        for(int i=1;i<=10&&i<w2;i++) ret |= !fun(h1, w1, h2, w2-i);
        return dp[h1][w1][h2][w2] = ret;
    }
    int main(){
        cin >> h1 >> w1 >> h2 >> w2;
        memset(dp, -1, sizeof(dp)); dp[1][1][1][1] = 0;
        cout << (fun(h1, w1, h2, w2)? "W" : "L") << endl;
        return 0;
    }