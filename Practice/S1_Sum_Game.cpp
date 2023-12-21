#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n]; int b[n];


    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> b[i];


    }
    int K=0;
    int sumA=0; int sumB=0;
    for(int i=0; i<n; ++i) {
        sumA+=a[i];
        sumB+=b[i];
        if(sumA==sumB) {
            K=i+1;
        }
    }
    cout << K;
    return 0;
}