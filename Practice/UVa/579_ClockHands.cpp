#include <bits/stdc++.h>
using namespace std;
int h, m; double ans, ah, am;
int main(){
    while(scanf("%d:%d", &h, &m) && (h||m)){
        am = m*6.0;
        if(h==12) h = 0;
        ah = h*30.0 + (m/60.0)*30.0;
        if(am > ah) ans = min(am-ah, ah+360-am);
        else ans = min(ah-am, am+360-ah); 
        printf("%.3lf\n", ans);
    }
    return 0;
}