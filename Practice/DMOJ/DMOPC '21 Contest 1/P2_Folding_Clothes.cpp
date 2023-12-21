#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+5;
int N, w[MM], M, ans[2*MM];
stack<int> a, b, temp;
bool sorted(){
    if(!b.empty()) return 0;
    bool flag = 1;
    int pre = 0;
    while(!a.empty()){
        if(a.top()<pre) {flag=0;break;}
        temp.push(a.top());
        pre=a.top();
        a.pop();
    }
    while(!temp.empty()){
        a.push(temp.top());
        temp.pop();
    }
    return flag;
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin>>w[i];
    for(int i=N-1;i>=0;i--) a.push(w[i]);
    bool first = 1;
    while(!sorted()){
        int mv = 0, pre;
        // a->b
        while(!a.empty()&&(b.empty()||a.top()<=b.top())&&a.top()>=pre){
            mv++;
            temp.push(a.top());
            pre = a.top();
            a.pop();
        }
        // if(first && a.empty()){M=0; break;}
        if(mv>0) ans[M++]=mv;
        while(!temp.empty()){b.push(temp.top()); temp.pop();}

        mv=0, pre=0;
        // b->a
        while(!b.empty()&&(a.empty()||b.top()<=a.top())&&b.top()>=pre){
            mv--;
            temp.push(b.top());
            pre = b.top();
            b.pop();
        }
        if(mv<0) ans[M++]=mv;
        while(!temp.empty()){a.push(temp.top()); temp.pop();}
        // if(b.empty()) break;
    }
    cout << M << endl;
    for(int i=0;i<M;i++) cout<<ans[i]<<endl;
    return 0;
}