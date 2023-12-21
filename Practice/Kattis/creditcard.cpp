#include <bits/stdc++.h>
using namespace std;
int T, ans=0; double R, B, M;
int main(){
    cin >> T;
    while(T--){
        cin >> R >> B >> M;
        ans=0;
        double cur = B;
        for(int i = 1;i<=1200;i++){
            cur = round(cur*(100.00 + R))/100.0;
            cur -= M;
            if(cur <= 0){
                cout << i << endl;
                break;
            }
            if(i == 1200) cout << "impossible\n";
        }
    }
    return 0;
}