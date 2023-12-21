#include <bits/stdc++.h>
using namespace std;
const int mx = 1e9+5, MM = 1005;
bool gone[MM]={0};
int N, term[MM], x[MM], y[MM], ans[MM], blked[MM];
char dir[MM];
int main(){
    cin >> N;
    memset(blked, -1, sizeof(blked));
    for(int i = 0;i<N;i++) {cin >> dir[i] >> x[i] >> y[i];term[i]=mx;}
    for(int i = 0;i<N;i++){
        int cur = 0, curM = 0, blk=-1;
        for(int j = 0;j<N;j++){
            if(x[j]+y[j]>curM && !gone[j]) curM = x[j]+y[j], cur = j;
        }
        gone[cur] = 1;
        for(int j = 0;j<N;j++){
            if(!gone[j] || cur == j) continue;
            if(x[j]+y[j]<=curM) continue;
            if(dir[cur]=='N'){
                if(dir[j]=='N'){
                    if(x[cur]==x[j]&&y[j]>y[cur]) if(term[cur] > y[j]) term[cur] = min(term[cur],y[j]), blk=j;
                }else{
                    if(term[j]>x[cur]&&x[j]<=x[cur]) if(term[cur] > y[j]) term[cur] = min(term[cur],y[j]), blk=j;
                }
            }else{
                if(dir[j]=='E'){
                    if(x[cur]<x[j]&&y[j]==y[cur]) if(term[cur] > x[j]) term[cur] = min(term[cur], x[j]), blk=j; 
                }else{
                    if(term[j]>y[cur]&&y[j]<=y[cur]) if(term[cur] > x[j]) term[cur] = min(term[cur],x[j]), blk=j;
                }
            }
        }
        blked[cur] = blk;
        while(blk != -1){
            ans[blk]++; blk=blked[blk];
        }
    }
    for(int i = 0;i<N;i++)
        cout << ans[i] << endl;
    return 0;
}