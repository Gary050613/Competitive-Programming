#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, arr[MM], dp[MM]={0}, a=0;
int main(){
    cin >> N;
    for(int i = 0;i<N;i++) cin >> arr[i];
    for(int i = 0;i<N;i++){
        if(arr[i]==a+1){
            a++;
        }
    }
    if(!a) cout << -1 << endl;
    else cout << N-a << endl;
    return 0;
}