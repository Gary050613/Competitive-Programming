#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
char f[MM][MM];
bool r[MM], c[MM];
int N, M, R, C, Rdiff, Cdiff, cur = 98;
char ran(){
    if(cur == 122) cur = 98;
    return cur++;
}
int main(){
    cin >> N >> M >> R >> C;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) f[i][j] = 'a';
        r[i]=1;
    }
    for(int i=1;i<=M;i++) c[i]=1;
    if(R!=N && C!=M){
        for(int i=R+1;i<=N;i++){
            for(int j=C+1;j<=M;j++){
                f[i][j] = ran();
            }
        }
    }else if(N==2){
        Rdiff = N-R;
        while(Rdiff >= 2){
            for(int i = 1;i<=N/2;i++){
                int e = N+1-i;
                if(r[i] && r[e] && f[i][1] == f[e][1]){
                    char ch = ran();
                    f[i][1] = ch;
                    f[e][1] = ch;
                    r[i] = 0; r[e] = 0;
                    Rdiff -= 2;
                    break;
                }
            }
        }
        Cdiff = M-C;
        while(Cdiff >= 2){
            for(int i = 1;i<=M/2;i++){
                int e = M+1-i;
                if(c[i] && c[e] && f[1][i] == f[1][e]){
                    char ch = ran();
                    f[1][i] = ch;
                    f[1][e] = ch;
                    c[i] = 0; c[e] = 0;
                    Cdiff -= 2;
                    break;
                }
            }
        }
    }else{
        Rdiff = N-R;
        Cdiff = M-C;
        // -1 from both
        if(Rdiff%2==1 && Cdiff%2==1){
            bool flag = 0;
            for(int i=1;i<=N;i++){
                if(N%2==1&&i==(N+1)/2) continue;
                for(int j=1;j<=M;j++){
                    if(M%2==1&&j==(M+1)/2) continue;
                    if(r[i] && c[j]){
                        flag = 1;
                        f[i][j] = 'z';
                        r[i] = 0; c[j] = 0;
                        Rdiff--; Cdiff--;
                        break;
                    }
                }
                if(flag) break;
            }
        }else if(Rdiff%2==1 && N%2==1){ // -1 from odd
            for(int i=1;i<=M;i++){
                if(M%2==1&&i==(M+1)/2) continue;
                if(r[(N+1)/2]){
                    f[(N+1)/2][i] = ran();
                    r[(N+1)/2] = 0;
                    Rdiff--;
                    break;
                }
            }
        }else if(Cdiff%2==1 && M%2==1){ // -1 from odd
            for(int i=1;i<=N;i++){
                if(N%2==1&&i==(N+1)/2) continue;
                if(c[(M+1)/2]){
                    f[i][(M+1)/2] = ran();
                    c[(M+1)/2] = 0;
                    Cdiff--;
                    break;
                }
            }
        }
        // -2 from 1 side
        while(Rdiff >= 2){
            int flag = 0;
            for(int j = 1;j<=M;j++){
                if(M%2==1&&j==(M+1)/2) continue;
                for(int i = 1;i<=N/2;i++){
                    int e = N+1-i;
                    if(r[i] && r[e] && f[i][j] == f[e][j]){
                        char ch = ran();
                        f[i][j] = ch;
                        f[e][j] = ch;
                        r[i] = 0; r[e] = 0;
                        Rdiff -= 2;
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        while(Cdiff >= 2){
            int flag = 0;
            for(int i = 1;i<=N;i++){
                if(N%2==1&&i==(N+1)/2) continue;
                for(int j = 1;j<=M/2;j++){
                    int e = M+1-j;
                    if(c[j] && c[e] && f[i][j] == f[i][e]){
                        char ch = ran();
                        f[i][j] = ch;
                        f[i][e] = ch;
                        c[j] = 0; c[e] = 0;
                        Cdiff -= 2;
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        // -1 from Broken Column
        if(Rdiff){
            bool flag = 0;
            for(int j = 1;j<=M;j++){
                if(M%2==1&&j==(M+1)/2) continue;
                if(!c[j]){
                    for(int i = 1;i<=N;i++){
                        if(r[i]){
                            f[i][j] = ran();
                            r[i] = 0;
                            Rdiff--;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
        }
        if(Cdiff){
            bool flag = 0;
            for(int i = 1;i<=N;i++){
                if(N%2==1&&i==(N+1)/2) continue;
                if(!r[i]){
                    for(int j = 1;j<=M;j++){
                        if(c[j]){
                            f[i][j] = ran();
                            c[j] = 0;
                            Cdiff--;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
        }
        
    }
    if(Cdiff || Rdiff) cout << "IMPOSSIBLE\n";
    else{
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=M;j++) cout << f[i][j];
            cout << endl;
        }
    }
    return 0;
}