/*
ID: gary0501
TASK: TASK_NAME_HERE
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e4+5;
// int l = 0, r = 5e8;
ll N, K, x[MM];
ll f(int R){
    int idx = 0, ans=0;
    while(idx < N){
        ll end = x[idx] + 2*R + 1;
        while(idx<N && x[idx]<end) idx++;
        ans++;
    }
    return ans;
}
int R(int l, int r){
    if(l == r) return l;
    int mid = (l+r)/2;
    if(K<f(mid)) return R(mid+1, r);
    else return R(l, mid);
}
int main(){
    cin >> N >> K;
    for(int i = 0;i<N;i++){
        cin >> x[i];
    }
    sort(x, x+N);
    cout << R(0, 1e9) << endl;
    return 0;
}


/*
1 3 8 10 18 20 25
 2 5 2  8  2  5
8 5 5 2 2 2

1 6 16 36 66

 4 5  10 10
1 5 10 20 30
K = 1
15
K = 2
5
k = 3
5
K = 4
2
K = 5
0

L R    L R

Figure out K-1 biggest intervals

Avoid the largest intervals

1 3 100 200 202
K = 1
101
K = 2
50
K = 3
1

 1 1 5 5  5  5  5  2  1
0 1 2 7 12 17 22 27 29 30
K = 1
15
K = 2
7
K = 3
4


Find a situation where the line is seperated into K areas with the max distance being the smallest
*/