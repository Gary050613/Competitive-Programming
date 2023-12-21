#include <bits/stdc++.h>
using namespace std;

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

typedef pair<int, int> pii;
#define fi first
#define se second
const int MM = 1e5+5;
int N, Q, fa[MM], ans[MM];
pair<int, pii> arr[MM], out[MM];
bool cmp1(pair<int, pii> a, pair<int, pii> b){return a.fi>b.fi;}
bool cmp2(pair<int, pii> a, pair<int, pii> b){return a.se.fi>b.se.fi;}
int find(int son){
    if(fa[son]==son) return son;
    else{
        fa[son] = find(fa[son]);
        return fa[son];
    }
}
void merge(int u, int v){
    ans[find(v)]+=ans[find(u)];
    ans[find(u)]=0;
    fa[find(u)] = find(v);
    // cout << u << " " << v << endl;
    // cout << find(u) << " " << find(v) << endl;
    // for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
    // cout << endl;
}
int main(){
    setIO("mootube");
    cin >> N >> Q;
    for(int i=1;i<=N;i++) fa[i]=i, ans[i]=1;
    for(int i=1, p, q, r;i<=N-1;i++){
        cin >> p >> q >> r;
        arr[i]={r, {p, q}};
    }
    for(int i=1, k, v;i<=Q;i++){
        cin >> k >> v;
        out[i]={i, {k, v}};
    }
    sort(arr+1, arr+N, cmp1);
    sort(out+1, out+Q+1, cmp2);
    // for(int i=1;i<=N-1;i++) cout<<arr[i].fi<<" "<<arr[i].se.fi<<" "<<arr[i].se.se<<endl;
    // for(int i=1;i<=Q;i++) cout<<out[i].fi<<" "<<out[i].se.fi<<" "<<out[i].se.se<<endl;
    int p=1;
    for(int i=1;i<=Q;i++){
        while(arr[p].fi>=out[i].se.fi) {merge(arr[p].se.fi, arr[p].se.se);p++;}
        out[i].se.fi=ans[find(out[i].se.se)];
        // cout << out[i].se.fi << endl;
    }
    sort(out+1, out+Q+1);
    for(int i=1;i<=Q;i++) cout<<out[i].se.fi-1<<endl;
    return 0;
}