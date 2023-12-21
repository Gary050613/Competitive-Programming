#include <bits/stdc++.h>
using namespace std;

struct friends{
	int a, b;
} f[5001];

bool cmp(friends f1, friends f2){
	return f1.a < f2.a;
}

int main(){
	
	int n, m[5001], ans = 0;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> f[i].a >> f[i].b;
	}
	sort(f+1, f+n+1, cmp);
//	for(int i = 1;i<=n;i++){
//		cout << f[i].a << " " << f[i].b << endl;
//	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<i;j++){
			if(f[j].b < f[i].b && m[i] <= m[j]){
				m[i] = m[j] + 1;
				ans = max(ans, m[i]);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}

/*
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2
*/
