#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int N;
double ans;
pair<int, int> T[MM];
int main(){
    cin >> N;
    for(int i = 0;i<N;i++) {cin >> T[i].first;T[i].second=i+1;}
    sort(T, T+N);
    for(int i = 0;i<N;i++) {cout << T[i].second << " "; ans+=T[i].first*(N-1-i);};
    cout << endl;
    printf("%.2lf", ans/N);
    return 0;
}