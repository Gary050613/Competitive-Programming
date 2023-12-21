// Debugging this problem was cancer
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> st1, st2, st3;
const int MM = 2e5+5;
string N, H;
const ll P1 = 1e9+7, P2 = 1e9+9, P3 = 1e9+21;
int needle[30], window[30], ans=0;
ll cur1=-1, cur2=-1, cur3=-1;
ll pow2(ll exp, ll prime){
    ll ret = 1, cur = 30;
    while(exp!=0){
        if(exp&1) ret=(ret*cur)%prime;
        cur=(cur*cur)%prime;
        exp>>=1;
    }
    return ret;
}
ll h(string str, ll prime){
    ll ret = 0, cnt=0;
    for(int i=str.length()-1;i>=0;i--){
        ret = (ret + (str[i]-'a')*pow2(cnt++, prime))%prime;
    }
    return ret;
}
int main(){
    cin >> N;
    cin >> H;
    if(N.length()>H.length()) {cout << 0 << endl;return 0;}
    for(int i=0;i<N.length();i++){
        needle[N[i]-'a']++;
        window[H[i]-'a']++;
    }
    int l = 0, r = N.length()-1;
    for(int i=0;i<30;i++){
        if(needle[i]!=window[i]) break;
        if(i==29) {
            ans++;
            string cur = H.substr(0, N.length());
            cur1 = h(cur, P1);
            st1.insert(cur1);
            cur2 = h(cur, P2);
            st2.insert(cur2);
            cur3 = h(cur, P3);
            st3.insert(cur3);
            // cout << "HERE" << endl;
            // cout << cur1 << endl;
        }
    }
    while(r < H.length()-1){
        if(cur1!=-1||cur2!=-1||cur3!=-1){
            // cur1 = ((cur1-(H[l]-'a'))/30+((H[r+1]-'a')*pow2(N.length()-1, P1)%P1))%P1;
            // cur2 = ((cur2-(H[l]-'a'))/30+((H[r+1]-'a')*pow2(N.length()-1, P2)%P2))%P2;
            // cur3 = ((cur3-(H[l]-'a'))/30+((H[r+1]-'a')*pow2(N.length()-1, P3)%P3))%P3;
            // if(l==0){
            //     // cout << cur1-(H[l]-'a') << endl;
            //     cout << (H[l]-'a')*pow2(N.length()-1, P1)%P1 << endl;
            //     cout << (H[r+1]-'a') << endl;
            // }
            cur1 = ((cur1+P1-(H[l]-'a')*pow2(N.length()-1, P1)%P1)*30+(H[r+1]-'a'))%P1;
            cur2 = ((cur2+P2-(H[l]-'a')*pow2(N.length()-1, P2)%P2)*30+(H[r+1]-'a'))%P2;
            cur3 = ((cur3+P3-(H[l]-'a')*pow2(N.length()-1, P3)%P3)*30+(H[r+1]-'a'))%P3;
        }
        window[H[++r]-'a']++;
        window[H[l++]-'a']--;
        for(int i=0;i<30;i++){
            if(needle[i]!=window[i]) break;
            if(i==29&&cur1==-1&&cur2==-1&&cur3==-1){
                ans++;
                string cur = H.substr(l, N.length());
                cur1 = h(cur, P1);
                st1.insert(cur1);
                cur2 = h(cur, P2);
                st2.insert(cur2);
                cur3 = h(cur, P3);
                st3.insert(cur3);
                // cout << "l: " << l << endl;
                // cout << cur1 << " " << cur2 << " " << cur3 << endl;
                // cout << cur1 << endl;
                // cout << r << endl;
                // cout<<"HERE"<< endl;
            }
            else if(i==29&&(st1.count(cur1)==0||st2.count(cur2)==0||st3.count(cur3)==0)) {
                ans++;
                // cout << l << endl;
                st1.insert(cur1);
                st2.insert(cur2);
                st3.insert(cur3);
                // cout << cur1 << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}