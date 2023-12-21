#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

vii graph[501];

int main(){
   int n;
   cin>>n;
   for(int i = 1; i < n+1;i++){
       for(int j = 1; j < n+1;j++){
           int t;
           cin>>t;
           if(t==100){
               graph[i].push_back(ii(j,1));
           } 
           if(t<100){
               graph[i].push_back(ii(j,-1));
           }
       }
   }
    ll ans = 0;
    int hundreds[501]={0};
    int less[501]={0};
    for(int i = 1; i < n+1;i++){
       for(int j = i; j < n+1; j++){
           for(ii cur:graph[j]){
               if(cur.second==1){
                   hundreds[cur.first]++;
               }else{less[cur.first]++;}
           }
           int prev = 0;
           int now = 0;
            for(int k = 1; k < 502;k++){
                if((less[k]!=0||hundreds[k]!=0||k==n+1) && now>prev){
                    ans+=(ll)(k-now)*(now-prev);
                    }
                if(less[k]>0){
                    prev=k;
                    continue;
                }
                if(hundreds[k]>0){
                    now = k;
                }
            }
       }
       memset(less,0,501*sizeof(*less));
       memset(hundreds,0,501*sizeof(*hundreds));
   }
  cout<<ans;
}
