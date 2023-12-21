#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5;
ll N, a[MM];
ll ans;
stack<int> s;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> a[i];
    for(int i=1;i<=N;i++){
        while(!s.empty()&&a[i]>a[s.top()]){
            ans += i-s.top()+1;
            s.pop();
        }
        if(!s.empty()) ans+=i-s.top()+1;
        s.push(i);
    }
    cout << ans << endl;
    return 0;
}