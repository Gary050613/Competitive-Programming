#include <bits/stdc++.h>
using namespace std;
const int MM = 14;
int N, hor[MM], diag1[2*MM], diag2[2*MM], ans, arr[MM], cnt=0; // 1:\ 2:/
void search(int v){
    if(v==N){
        if(cnt<3){
            for(int i = 0;i<N;i++) cout<<arr[i]+1<<" ";
            cout << endl; cnt++;
        }
        ans++; return;
    }
    for(int i = 0;i<N;i++){
        if(!hor[i]&&!diag1[i+N-v]&&!diag2[i+v]){hor[i]=1, diag1[i+N-v]=1, diag2[i+v]=1, arr[v]=i; search(v+1); hor[i]=0, diag1[i+N-v]=0, diag2[i+v]=0;}
    }
}
int main(){
    cin >> N;
    search(0);
    cout << ans << endl;
    return 0;
}