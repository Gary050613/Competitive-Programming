#include <bits/stdc++.h>
using namespace std;
int N, A, B, arr[205], ans[205], res=205;
bool flag[205]={0};
int main(){
    cin >> N >> A >> B;
    if(A==B) {cout << 0 << endl; return 0;}
    ans[B]=-1;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    queue<int> q;
    q.push(A);
    flag[A]=1;
    while(!q.empty()){
        int up = arr[q.front()]+q.front();
        int down = q.front()-arr[q.front()];
         //use flag as a enqueue log ? who has been through the queue.. unless you want the node to enqueue multiple times.
        if(up<=N && !flag[up]){
            q.push(arr[q.front()]+q.front());
            flag[arr[q.front()]+q.front()] = 1;
            ans[arr[q.front()]+q.front()]=ans[q.front()]+1;
        }
        if (up == B) break;
        if(down>=1 && !flag[down]){
            q.push(q.front()-arr[q.front()]);
            flag[q.front()-arr[q.front()]] = 1;
            ans[q.front()-arr[q.front()]]=ans[q.front()]+1;
        }
        if (down==B) break;
        q.pop();
    }
    cout << ans[B] << endl;
    return 0;
}