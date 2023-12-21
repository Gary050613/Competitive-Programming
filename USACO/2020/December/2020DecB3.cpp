#include <bits/stdc++.h>
using namespace std;
const int mx = 1e9+5, MM = 55;
bool gone[MM]={0};
int N, term[MM], x[MM], y[MM];
char dir[MM];
int main(){
    cin >> N;
    for(int i = 0;i<N;i++) {cin >> dir[i] >> x[i] >> y[i];term[i]=mx;}
    for(int i = 0;i<N;i++){
        int cur = 0, curM = 0;
        for(int j = 0;j<N;j++){
            if(x[j]+y[j]>curM && !gone[j]) curM = x[j]+y[j], cur = j;
        }
        gone[cur] = 1;
        for(int j = 0;j<N;j++){
            if(!gone[j] || cur == j) continue;
            if(x[j]+y[j]<=curM) continue;
            if(dir[cur]=='N'){
                if(dir[j]=='N'){
                    if(x[cur]==x[j]&&y[j]>y[cur]) term[cur] = min(term[cur],y[j]);
                }else{
                    if(term[j]>x[cur]&&x[j]<=x[cur]) term[cur] = min(term[cur],y[j]);
                }
            }else{
                if(dir[j]=='E'){
                    if(x[cur]<x[j]&&y[j]==y[cur]) term[cur] = min(term[cur], x[j]); 
                }else{
                    if(term[j]>y[cur]&&y[j]<=y[cur]) term[cur] = min(term[cur],x[j]);
                }
            }
        }
    }
    // for(int i = 0;i<N;i++){
    //     for(int j = 0;j<N;j++){
    //         if(i==j) continue;
    //         if(dir[i]=='E'&&dir[j]=='N'&&y[i]>y[j]&&x[i]<x[j]&&(y[i]-y[j])<(x[j]-x[i])) ans[i] = min(ans[i],x[j]-x[i]);
    //         if(dir[i]=='N'&&dir[j]=='E'&&y[i]<y[j]&&x[i]>x[j]&&(y[j]-y[i])>(x[i]-x[j])) ans[i] = min(ans[i],y[j]-y[i]);
    //         if(dir[i]=='N'&&dir[j]=='N'&&x[i]==x[j]&&y[j]>y[i]) ans[i] = min(ans[i],y[j]-y[i]);
    //         if(dir[i]=='E'&&dir[j]=='E'&&x[i]<x[j]&&y[j]==y[i]) ans[i] = min(ans[i],x[j]-x[i]);
    //     }
    // }
    // for(int i = 0;i<N;i++) cout << term[i] << " ";
    for(int i = 0;i<N;i++)
        if(term[i]==mx) cout << "Infinity\n";
        else{if(dir[i]=='N') cout << term[i]-y[i] << endl; else cout << term[i]-x[i] << endl;}
    return 0;
}