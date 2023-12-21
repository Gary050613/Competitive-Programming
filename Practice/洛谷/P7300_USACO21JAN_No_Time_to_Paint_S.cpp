#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, Q, prefix[MM], suffix[MM], arr[MM], front[30]={0}, cnt=0, a, b;
int main(){
    cin >> N >> Q;
    char ch;
    for(int i=1;i<=N;i++){
        cin >> ch;
        arr[i]=ch-'A'+1;
    }
    // prefix[i] = How many times to paint to here
    for(int i=1;i<=N;i++){
        for(int j=26;j>arr[i];j--){
            if(front[j]){
                front[j]=0;
            }
        }
        if(!front[arr[i]]) cnt++;
        front[arr[i]]=1;
        prefix[i]=cnt;
    }
    // for(int i=1;i<N;i++) prefix[i]+=prefix[i-1];
    // for(int i=0;i<N;i++) cout<<prefix[i] << " ";
    cnt=0; memset(front, 0, sizeof(front));
    for(int i=N;i>=1;i--){
        for(int j=26;j>arr[i];j--){
            if(front[j]){
                front[j]=0;
            }
        }
        if(!front[arr[i]]) cnt++;
        front[arr[i]]=1;
        suffix[i]=cnt;
    }
    // cout << "HELLO" << endl;
    while(Q--){
        cin >> a >> b;
        cout << prefix[a-1] + suffix[b+1] << endl;
    }
    return 0;
}