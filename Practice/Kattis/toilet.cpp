#include <bits/stdc++.h>
using namespace std;
string in; char cur; int ans = 0;
int main(){
    cin >> in;
    // First policy
    cur = in[0];
    ans = 0;
    for(int i = 1;i<in.length();i++){
        // Comes in
        if(in[i] != cur){cur = in[i]; ans++;}
        // Goes out
        if(cur != 'U'){cur = 'U'; ans++;}
    }
    cout << ans << endl;
    // Second policy
    cur = in[0];
    ans = 0;
    for(int i = 1;i<in.length();i++){
        if(in[i] != cur){cur = in[i]; ans++;}
        if(cur != 'D'){cur = 'D'; ans++;}
    }
    cout << ans << endl;
    // Third policy
    cur = in[0];
    ans = 0;
    for(int i = 1;i<in.length();i++){
        if(in[i] != cur){cur = in[i]; ans++;}
    }
    cout << ans << endl;
    return 0;
}