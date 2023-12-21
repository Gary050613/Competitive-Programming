#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, M, arr[MM];
void update(){
    for(int i = 0;i<N-1;i++){
        if(arr[i+1]) arr[i] = !arr[i];
    }
    if(arr[0]) arr[N-1] = !arr[N-1];
}
int main(){
    cin >> N >> M;
    for(int i = 0;i<N;i++) cin >> arr[i];
    while(M--){
        update();
    }
    for(int i = 0;i<N;i++) cout << arr[i] << endl;
    return 0;
}