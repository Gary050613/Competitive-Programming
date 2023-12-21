// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int MM = 205;
string str = "WING";
int W, I, N, G, ans;
bool m[50][4], dp[MM][MM][4];
int ctoi(char ch){
    int x;
    for(int i=0;i<4;i++) if(str[i]==ch) x = i;
    return x;
}
int main(){
    cin >> W >> I >> N >> G;
    string s;
    while(W--){
        cin >> s;
        int a = ctoi(s[0])*10+ctoi(s[1]);
        m[a][0]=1;
    }
    while(I--){
        cin >> s;
        int a = ctoi(s[0])*10+ctoi(s[1]);
        m[a][1]=1;
    }
    while(N--){
        cin >> s;
        int a = ctoi(s[0])*10+ctoi(s[1]);
        m[a][2]=1;
    }
    while(G--){
        cin >> s;
        int a = ctoi(s[0])*10+ctoi(s[1]);
        m[a][3]=1;
    }
    cin>>s;
    for(int i=0;i<s.length();i++) dp[i][i][ctoi(s[i])]=1;
    for(int w = 1;w<s.length();w++){
        for(int l=0;l+w<s.length();l++){
            int r = l+w;
            for(int k=l;k+1<=r;k++){
                for(int a=0;a<4;a++){
                    for(int b=0;b<4;b++){
                        for(int c=0;c<4;c++){
                            if(dp[l][k][a]&&dp[k+1][r][b]&&m[a*10+b][c]) dp[l][r][c]=1;
                        }
                    }
                }
            }
        }
    }
    bool flag=0;
    for(int i=0;i<4;i++) if(dp[0][s.length()-1][i]) {cout << str[i];flag=1;}
    if(!flag) cout<<"The name is wrong!";
    cout<<endl;
    return 0;
}