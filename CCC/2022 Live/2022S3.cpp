#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, M, K, arr[MM], cnt=0, cur;
int main(){
    cin >> N >> M >> K;
    cur = ((1+M)*M/2)+(N-M)*M;
    if(K>cur||K<N) {cout << -1 << endl; return 0;}
    if(M==2){
        cur = N;
        for(int i=1;i<=N;i++) arr[i] = 1;
        while(cur<K){
            if(K-2>=N) {arr[N-(2*cnt++)-1]=2;K-=2;}
            else {
                arr[N]=2;K--;
                }
        }
    }else if(M==N){
        cnt = 1;
        for(int i=1;i<=N;i++){
            arr[i] = cnt++;
            if(cnt > M) cnt = 1;
        }
    }
    for(int i=1;i<=N;i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}