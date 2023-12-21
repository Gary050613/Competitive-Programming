#include <bits/stdc++.h>
using namespace std;
int n, s, d;
int main(){
    cin >> n;
    while(n--){
        cin >> s >> d;
        if(s<d || (s+d)%2==1){cout << "impossible\n"; continue;};
        cout << (s+d)/2 << " " << (s-d)/2 << endl;
    }
    return 0;
}