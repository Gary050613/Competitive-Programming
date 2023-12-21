#include <bits/stdc++.h>
using namespace std;
int C, ans;
bool tiles[200005][2];
int main(){
    cin >> C;
    for(int i=1;i<=C;i++){
        cin >> tiles[i][0];
        if(tiles[i][0]){
            if(!tiles[i-1][0]){
                ans += 2;
            }
        }
    }
    for(int i=1;i<=C;i++){
        cin >> tiles[i][1];
        if(tiles[i][1]){
            if(!tiles[i-1][1]){
                ans += 2;
            }
        }
    }
    for(int i=1;i<=C;i++){
        if(i%2==1){
            if(tiles[i][0]^tiles[i][1]) ans++;
        }else{
            ans += tiles[i][0] + tiles[i][1];
        }
    }
    cout << ans << endl;
    return 0;
}