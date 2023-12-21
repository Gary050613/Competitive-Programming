#include <bits/stdc++.h>
using namespace std;
int T, K;
string n;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> K;
        priority_queue<int, vector<int>, greater<int>> pq;
        stack<int> st;
        for(int i = 0;i<n.length();i++){
            int num = n[i]-'0';
            while(!st.empty() && num<st.top() && K>0){
                int cur = st.top();
                pq.push(cur);
                st.pop();
                K--;
            }
            st.push(num);
        }
        while(K>0 && !st.empty() && !pq.empty() && pq.top()<st.top()){
            pq.push(st.top());
            st.pop();
            K--;
        }
        string ans="";
        while(!st.empty()) {ans = to_string(st.top()) + ans; st.pop();}
        while(!pq.empty()) {ans = ans + to_string(pq.top()); pq.pop();}
        cout << ans << endl;
    }
    return 0;
}