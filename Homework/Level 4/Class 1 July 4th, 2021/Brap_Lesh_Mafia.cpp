#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, a, b, sum=0;
int main(){
    cin >> N >> K;
    while(N--){
        cin >> a >> b;
        sum= (sum+(a%K)*(b%K))%K;
    }
    cout << sum << endl;
    return 0;
}