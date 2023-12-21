#include<iostream>
#include<cmath>
#include<algorithm>

struct zombie{
 
 int v1,v2,num;
 bool live;
 int dis;
};
 
zombie zom[50001];

int main(){

 int i , n;
 cin >> n;
 int m = n;
 for(i = 1; i <= n; i++){
  cin >> zom[i].v1 >> zom[i].v2;
  zom[i].num = i;
  zom[i].live = true;
 }
 
 int k = 1;
 for(i = 2; i <= n; i++){
  if(zom[k].v1 < zom[i].v1)
   k = i;
 }
 cout << k << " ";
 zom[k].live = false;
 n--;
 
 int t = 1;
 while(n > 0){
  int Max = 0,number = 0;
  for(int i = 1;i <= m; i++){
   if(zom[i].live == true){
    zom[i].dis = zom[i].v1 + zom[i].v2 * t;
    if(Max < zom[i].dis){
     Max = zom[i].dis;
     number = i;
    }
   }
  }
  cout << number << " ";
  zom[number].live = false;
  t++;
  n--;
 }

 return 0;
}
