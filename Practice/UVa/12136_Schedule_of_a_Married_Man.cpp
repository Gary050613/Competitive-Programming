#include <bits/stdc++.h>
using namespace std;
int N, start, send, ms, me, a, b, c, d;
int main(){
    cin >> N;
    for(int cnt = 1;cnt<=N;cnt++){
        scanf("%d:%d %d:%d", &a, &b, &c, &d);
        start = a*60 + b;
        send = c*60 + d;
        scanf("%d:%d %d:%d", &a, &b, &c, &d);
        ms = a*60 + b;
        me = c*60 + d;
        printf("Case %d: ", cnt);
        if((ms < start && me < start) || (ms > send && me > send)) cout << "Hits Meeting\n";
        else cout << "Mrs Meeting\n";
    }
    return 0;
}