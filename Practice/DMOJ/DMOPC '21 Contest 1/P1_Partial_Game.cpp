#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
ll N, arr[MM], d, a;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        if(arr[i]%2==0){
            // Duke
            d+=(arr[i]+1)/2;
        }else{
            // Alice
            a+=(arr[i]+1)/2;
        }
    }
    if(d>a) cout << "Duke\n";
    else cout << "Alice\n";
    return 0;
}