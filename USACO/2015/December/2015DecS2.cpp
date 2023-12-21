#include <bits/stdc++.h>
using namespace std;
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int MM = 5e4+5;
int N, a, ans=0;
bool arr[2*MM]={0};
priority_queue<int> B, E;
int main(){
    setIO("highcard");
    cin >> N;
    for(int i=0;i<N;i++){cin>>a;arr[a]=1;E.push(a);}
    for(int i=1;i<=2*N;i++){
        if(!arr[i]) B.push(i);
    }
    while(!B.empty() && !E.empty()){
        // cout << B.top() << " " << E.top() << endl;
        if(B.top()>E.top()){ans++; B.pop(); E.pop();}
        else E.pop();
    }
    cout << ans << endl;
    return 0;
}