#include <bits/stdc++.h>
using namespace std;
int N, ans;
int main(){
    cin >> N;
    for(int i=0;i<=N;i++){
        if(i%5==0&&(N-i)%4==0) ans++;
    }
    cout << ans << endl;
    return 0;
}