#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
ll N, T, L, R, a, b, c, dif1[MM]={0}, dif2[MM]={0}, dif3[MM]={0};
int main(){
    cin >> N >> T;
    while(N--){
        cin >> L >> R >> a >> b >> c;
        dif1[L+1] += a, dif1[L+2] += a, dif1[R+1] -= a*(R-L+1)*(R-L+1), dif1[R+2] += ((R-L)*(R-L)*3-(R-L-1)*(R-L-1))*a, dif1[R+3] -= (R-L)*(R-L)*a;
        dif2[L+1]+=b, dif2[R+1]-=(R+1-L)*b, dif2[R+2]+=(R-L)*b;
        dif3[L]+=c, dif3[R+1]-=c;
    }
    for(int t = 0;t<3;t++){
        for(int i = 1;i<=T;i++){
            dif1[i]+=dif1[i-1];
        }
    }
    for(int t = 0;t<2;t++){
        for(int i = 1;i<=T;i++){
            dif2[i]+=dif2[i-1];
        }
    }
    for(int i = 1;i<=T;i++){
        dif3[i]+=dif3[i-1];
        cout << dif1[i] + dif2[i] + dif3[i] << " ";
    }
    return 0;
}