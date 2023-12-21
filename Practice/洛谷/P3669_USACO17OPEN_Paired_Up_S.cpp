#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

bool cmp(pii a, pii b){return a.se > b.se;}
const int MM = 1e5+5;
int N, ans=0;
pii arr[MM];
int main(){
    cin >> N;
    for(int i = 0;i<N;i++) cin>>arr[i].fi>>arr[i].se;
    sort(arr, arr+N, cmp);
    int l=0,r=N-1;
    while(l<=r){
        ans=max(ans, arr[l].se+arr[r].se);
        // cout << "HI";
        if(arr[l].fi>arr[r].fi) {arr[l].fi-=arr[r].fi;arr[r].fi=0;r--;}
        else if(arr[l].fi<arr[r].fi) {arr[r].fi-=arr[l].fi;arr[l].fi=0;l++;}
        else arr[l].fi=0,arr[r].fi=0,l++,r--;
        // if(arr[l].fi==0) l++;
        // if(arr[r].fi==0) r--;
    }
    cout << ans << endl;
    return 0;
}