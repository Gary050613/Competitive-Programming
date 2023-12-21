#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, a[MM];
stack<int> st;
int main(){
    cin.tie(NULL);ios_base::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a[i];
        while(!st.empty() && a[i]>=a[st.top()]){
            st.pop();
        }
        if(st.empty()) cout << i << " ";
        else cout << i-st.top() << " ";
        st.push(i);
    }
    return 0;
}