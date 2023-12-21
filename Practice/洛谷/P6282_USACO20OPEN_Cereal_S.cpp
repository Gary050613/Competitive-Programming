#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M, c[MM], ans[MM], f[MM], s[MM], cnt=0;
bool v[MM];
void take(int cow, int cer){
    if(c[cer]==0){
        c[cer]=cow;
        cnt++; return;
    }else{
        if(cow<c[cer]){
            if(cer==f[c[cer]]){
                take(c[cer], s[c[cer]]);
            }
            c[cer]=cow;
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin>>f[i]>>s[i];
    for(int i=N;i>=1;i--){
        take(i, f[i]);
        ans[i]=cnt;
    }
    for(int i=1;i<=N;i++) cout<<ans[i]<<endl;
    return 0;
}