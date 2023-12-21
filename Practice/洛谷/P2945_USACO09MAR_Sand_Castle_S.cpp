#include <bits/stdc++.h>
using namespace std;
const int MM = 25005;
int N, X, Y, M[MM], B[MM], ans=0;
int main(){
    cin >> N >> X >> Y;
    for(int i = 0;i<N;i++) cin >> M[i] >> B[i];
    sort(M,M+N); sort(B,B+N);
    for(int i = 0;i<N;i++) 
        if(B[i]>M[i]) ans+=X*(B[i]-M[i]);
        else if(B[i]<M[i]) ans+=Y*(M[i]-B[i]);
    cout << ans << endl;
    return 0;
}