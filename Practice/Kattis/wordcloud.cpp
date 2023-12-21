#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int w, n, sz[MM], t=1; string word[MM]; 
int main(){
    while(cin >> w >> n && (w||n)){
        int cmax=0, cur=0, curM=0, ans=0;
        for(int i = 0;i<n;i++) {cin >> word[i] >> sz[i]; cmax = max(cmax, sz[i]);}
        for(int i = 0;i<n;i++){
            int P = 8 + ceil(40*((double) sz[i]-4.0)/((double) cmax-4.0));
            int width = ceil(9.0/16.0*(double)word[i].length()*(double)P);
            // cout << P << " " << width << endl;
            if(cur!=0){
                if((cur + 10 + width)>w){
                    cur = width;
                    ans+=curM;
                    curM = P;
                    // cout << width << " SWITCHED\n";
                }else cur+=10+width;
            }else cur += width;
            curM = max(curM, P);
            // cout << ans << endl;
        }
        ans += curM;
        printf("CLOUD %d: %d\n", t++, ans);
    }
    return 0;
}