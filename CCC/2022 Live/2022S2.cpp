#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
// set<int> st1, st2, st3;
const ll P1 = 1e9+7, P2 = 1e9+9;
int X, Y, G, cnt=1, fa[MM], ans;
pair<int, int> tog[MM], sep[MM];
string str, a, b, c;
unordered_map<ll, int> mp1, mp2;
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
        ret = (ret + (str[i]-'A')*pow2(cnt++, prime))%prime;
    }
    return ret;
}
int mp(string str){
    if(mp1[h(str, P1)]==0||mp2[h(str, P2)]==0||mp1[h(str, P1)]!=mp2[h(str, P2)]){
        fa[cnt]=cnt;
        mp1[h(str, P1)]=cnt;
        mp2[h(str, P2)]=cnt++;
    }
    return mp1[h(str, P1)];
}
int find(int x){
    if(fa[x]==x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
void uni(int a, int b){
    fa[find(a)] = find(b);
}
int main(){
    cin >> X;
    for(int i=1;i<=X;i++){
        cin >> str;
        tog[i].first = mp(str);
        cin >> str;
        // if(mp[str]==0) mp[str] = cnt++;
        tog[i].second = mp(str);
    }
    cin >> Y;
    for(int i=1;i<=Y;i++){
        cin >> str;
        // if(mp[str]==0) mp[str] = cnt++;
        sep[i].first = mp(str);
        cin >> str;
        // if(mp[str]==0) mp[str] = cnt++;
        sep[i].second = mp(str);
    }
    for(int i=1;i<cnt;i++) fa[i] = i;
    cin >> G;
    for(int i=1;i<=G;i++){
        cin >> a >> b >> c;
        // if(mp[a]==0) {mp[a]=cnt++; fa[mp[a]]=mp[a];}
        // if(mp[b]==0) {mp[b]=cnt++; fa[mp[b]]=mp[b];}
        // if(mp[c]==0) {mp[c]=cnt++; fa[mp[c]]=mp[c];}
        uni(mp(a), mp(b));
        uni(mp(a), mp(c));
    }
    for(int i=1;i<=X;i++){
        if(find(tog[i].first)!=find(tog[i].second)) ans++;
    }
    for(int i=1;i<=Y;i++){
        if(find(sep[i].first)==find(sep[i].second)) ans++;
    }
    cout << ans << endl;
    return 0;
}