// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MM = 1e5+5;
ll N, f[MM][4][4][4], ans;
string s, str="ATCG";
int ctoi(char ch){
    for(int i=0;i<4;i++) if(ch==str[i]) return i;
    return 0;
}
int main(){
    cin >> s;
    N = s.length();
    for(int i=0;i<4;i++){
        if(s[0]=='?'){
            for(int j=0;j<4;j++) f[0][i][j][j] = 1;
        }else f[0][i][ctoi(s[0])][ctoi(s[0])] = 1;
    }
    for(int k=1;k<N;k++){
        for(int sk = 0;sk<4;sk++){
            if(s[k]=='?'||s[k]==str[sk]){
                for(int n=0;n<4;n++){
                    for(int l=0;l<4;l++){
                        for(int m=0;m<4;m++){
                            if(sk!=m) {f[k][n][l][sk] += f[k-1][n][l][m]; f[k][n][l][sk]%=MOD;}
                            if(n==m) {f[k][l][sk][sk] += f[k-1][n][l][m]; f[k][l][sk][sk]%=MOD;}
                        }
                    }
                }
            }
        }
    }
    for(int l=0;l<4;l++){
        for(int m=0;m<4;m++){
            ans += f[N-1][m][l][m];
        }
    }
    ans = ans%MOD;
    cout << ans << endl;
    return 0;
}