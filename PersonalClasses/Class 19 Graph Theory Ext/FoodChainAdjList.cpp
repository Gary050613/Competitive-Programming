#include<bits/stdc++.h>
using namespace std;
const int mod=80112002;
int n, m, h[5005], ru[5005], chu[5005], f[5005], ans;
struct AB{
   int a,b,n;
}d[5000005];
queue<int> q;
int main(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
    int a, b;
       scanf("%d%d", &a, &b);
       d[i].a=a, d[i].b=b, d[i].n=h[a], h[a]=i;//??
       chu[a]++, ru[b]++;
   }
   for(int i=1;i<=n;i++){
       if(ru[i]==0) {
           f[i]=1;
           q.push(i);
       }
   }
   while(!q.empty()){
       int a=q.front();
       q.pop();
       for(int k=h[a];k;k=d[k].n){
           int b=d[k].b;
           f[b]+=f[a];
           f[b]%=mod;
           ru[b]--;
           if(ru[b]==0){
               if(chu[b]==0){
                   ans+=f[b];
                   ans%=mod;
               }//???0????????,????,??????
               else q.push(b);
           }
       }
   }
   cout<<ans; 
}
