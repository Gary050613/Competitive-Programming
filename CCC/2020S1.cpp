#include <bits/stdc++.h>
using namespace std;

struct measure{
    double t, loc;
} measurements[100001];

bool comp(measure m1, measure m2){
    if(m1.t < m2.t){
        return true;
    }
    return false;
}

int main(){

    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> measurements[i].t >> measurements[i].loc;
    }
    sort(measurements+1, measurements+n+1,comp);
    double maxS = 0.0;
    for(int i = 1;i<n;i++){
        maxS = max(maxS,abs(measurements[i+1].loc - measurements[i].loc)/(measurements[i+1].t-measurements[i].t));
    }
    printf("%.1f", maxS);
    return 0;
}


