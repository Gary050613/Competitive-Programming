#include <bits/stdc++.h>
using namespace std;
const int MM = 655;
int N, psa[MM][MM]={0}, mx=651;
int main(){
    cin >> N; vector<int> a(N+1), b(N+1);
    for(int i=1; i<=N;i++){
        cin >> a[i] >> b[i]; a[i]++, b[i]++; psa[a[i]][b[i]]++;
    }
    for(int i=1;i<=mx;i++)
        for(int j=1;j<=mx;j++)
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    for(int i=1;i<=N;i++){
        int best = psa[mx][mx] - psa[mx][b[i]] - psa[a[i]][mx] + psa[a[i]][b[i]];
        int worst = psa[a[i]-1][b[i]-1];
        if(a[i]==mx) worst += psa[1][b[i]] - psa[1][b[i]-1];
        if(b[i]==mx) worst += psa[a[i]][1] - psa[a[i]-1][1];
        cout << best + 1 << " " << (N-worst) << "\n";
    }
    return 0;
}