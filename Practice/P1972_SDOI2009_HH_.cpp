#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
typedef pair<int, int> pii;
int N, M, t[MM], cnt=1, last[MM], ans[MM];
pii arr[MM];
pair<int, pii> q[MM];
bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
bool cmp1(pair<int, pii> a, pair<int, pii> b){
    if(a.second.second == b.second.second) return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}
int lowbit(int x){return x&-x;}
int get(int i){
    int sum = 0;
    while(i>0){
        sum+=t[i];
        i-=lowbit(i);
    }
    return sum;
}
void add(int i, int x){
    while(i<=N){
        t[i]+=x;
        i+=lowbit(i);
    }
}
int main(){
    cin >> N;
    for(int i=1, a;i<=N;i++){
        cin >> a;
        if(last[a]==0) last[a] = i;
        else{
            arr[cnt++] = {last[a], i};
            last[a] = i;
        }
    }
    cin >> M;
    for(int i=1;i<=M;i++) {cin >> q[i].second.first >> q[i].second.second; q[i].first=i;}
    sort(q+1, q+M+1, cmp1);
    sort(arr+1, arr+cnt, cmp);
    int j=1;
    for(int i=1;i<=M;i++){
        while(j<cnt&&q[i].second.second >= arr[j].second){
            add(arr[j].first, 1);
            j++;
        }
        ans[q[i].first] = q[i].second.second - q[i].second.first + 1 - (get(q[i].second.second) - get(q[i].second.first-1));
    }
    for(int i=1;i<=M;i++){
        cout << ans[i] << endl;
    }
    return 0;
}