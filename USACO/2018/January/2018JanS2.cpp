#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
typedef pair<int, int> pii;
ll N, M, R, rent[MM], cow[MM], ans=0;
pii shop[MM];
void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
void showS(){for(int i=0;i<M;i++) cout << shop[i].first << " " << shop[i].second << endl;}
bool cmp(pii a, pii b){
    return a.first > b.first;
}
bool cmp1(int a, int b){return a > b;}
int main(){
    setIO("rental");
    cin >> N >> M >> R;
    for(int i=0;i<N;i++) cin>>cow[i];
    for(int i=0;i<M;i++) cin>>shop[i].second>>shop[i].first;
    for(int i=0;i<R;i++) cin>>rent[i];
    sort(shop, shop+M, cmp);
    sort(rent, rent+R, cmp1);
    sort(cow, cow+N, cmp1);
    int pShop = 0, pRent=0;
    int r = N;
    for(int i=0;i<r;i++){
        ll rem = cow[i], value=0;
        int cur=pShop;
        while(rem>0 && cur<M){
            if(rem >= shop[cur].second){
                rem -= shop[cur].second;
                value += shop[cur].first*shop[cur].second;
                cur++;
            }else{
                value += shop[cur].first*rem;
                rem=0;
            }
        }
        if(value >= rent[pRent] || pRent>=R){
            ans += value;
            rem = cow[i];
            while(rem>0 && pShop<M){
                if(rem >= shop[pShop].second){
                    rem -= shop[pShop].second;
                    shop[pShop].second=0;
                    pShop++;
                }else{
                    shop[pShop].second -= rem;
                    rem=0;
                }
            }
            // cout << cow[i] << " SHOP " << value << endl;
        }else{
            ans += rent[pRent++];
            r--, i--;
            // cout << cow[i] << " RENT " << value << endl;
        }
        // showS();
    }
    cout << ans << endl;
    return 0;
}