#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, ans[MM];
int main(){
    cin >> N;
    int a, b;
    cin >> a;
    for(int i=1;i<=N;i++){
        cin >> b;
        if(a>b) ans[b]++, ans[a]--;
        a=b;
    }
    for(int i=1;i<=N;i++){
        
    }
    return 0;
}