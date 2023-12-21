#include <iostream>
#include <algorithm>
#define INF 100000000

using namespace std;

int main(){
    string s;
    cin>>s;
    int L = 0,M = 0,S = 0;
    for(char c:s){
        if(c=='L'){
            L++;
        }
        if(c=='M'){
            M++;
        }
        if(c=='S'){
            S++;
        }
    }
    //M in L
    int LM=0,ML=0,LS=0,SL=0,MS=0,SM=0;
    for(int i = 0; i < L;i++){
        if(s[i]=='M'){
            LM++;
        } 
        if(s[i]=='S'){
            LS++;
        }
    }
    for(int i = L; i < L+M;i++){
         if(s[i]=='L'){
            ML++;
        } 
        if(s[i]=='S'){
            MS++;
        }
    }
      for(int i = L+M; i < L+M+S;i++){
         if(s[i]=='L'){
            SL++;
        } 
        if(s[i]=='M'){
            SM++;
        }
    }
    if(M==0){
        cout<<LS;
    } else{
        cout<<LM+LS+ML+MS-min(LM,ML);
    }
    
    return 0;
}
