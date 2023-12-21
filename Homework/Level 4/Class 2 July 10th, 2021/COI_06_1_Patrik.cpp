#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e5+5;
int N, arr[MM]={0};
ll ans=0, a=0;
struct s{
    int trail, val;
};
int main(){
    cin >> N;
    for(int i = 0;i<N;i++) cin >> arr[i];
    stack<s> st;
    for(int i = 0;i<N;i++){
        ll cnt=0;
        while(!st.empty() && arr[i]>st.top().val){
            cnt++; st.pop();
        }
        ans += cnt;
        s h; h.val = arr[i], h.trail=1;
        if(!st.empty()&&arr[i]==st.top().val) {
            h.trail = st.top().trail+1, ans+= st.top().trail;
            if(st.size()>st.top().trail) ans++;
        }else if(!st.empty()) ans++;
        st.push(h);
        
        // cout << cnt+a << " ";
    }
    cout << ans << endl;
    return 0;
}