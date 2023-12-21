#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tree[100][100] = {0};
int ans = 0;
char ch;

void solve(int tlx, int tly, int brx, int bry){
	cin >> ch;
	if(ch == 'e'){
		return;
	}
	if(ch == 'f'){
		for(int i = tlx; i<=brx;i++){
			for(int j = tly; i<=bry;j++){
				tree[i][j] = 1;
			}
		}
		return;
	}
	if(ch == 'p'){
		solve(tlx, (tly+bry)/2, (tlx+brx)/2, bry);
		solve(tlx, tly, (tlx+brx)/2, (tly+bry)/2);
		solve((tlx+brx)/2, tly, (tly+bry)/2, brx);
		solve((tlx+brx)/2, (tly+bry)/2, brx, bry);
	}
	return;
}

int main(){
	
	int n;
	char a;
	cin >> n;
	while(n--){
		tree[100][100] = {0};
		ans = 0;
		solve(1, 1, 32, 32);
		solve(1, 1, 32, 32);
		for(int i = 1;i<=32;i++){
			for(int j = 1;j<=32;j++){
				ans += tree[i][j];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}


