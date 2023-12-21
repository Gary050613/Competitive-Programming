#include <bits/stdc++.h>
using namespace std;
int n, t, a;
double pec, arr[105]={0};
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++) cin >> arr[i];
    while(cin >> t && t!=77){
        if(t == 99){
            cin >> a >> pec; 
            for(int i=n;i>=a;i--) arr[i+1] = arr[i];
            arr[a] *= pec/100;
            arr[a+1] -= arr[a];
            n++;
        }else{
            cin >> a;
            arr[a] += arr[a+1];
            for(int i=a+1;i<=n;i++) arr[i] = arr[i+1];
            n--;
        }
    }
    for(int i = 1;i<=n;i++) cout << arr[i] << " ";
    return 0;
}