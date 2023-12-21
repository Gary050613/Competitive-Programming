#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream cin("square.in");
	ofstream cout("square.out");
	
	int bx1, by1, tx1, ty1, bx2, by2, tx2, ty2;
	cin >> bx1 >> by1 >> tx1 >> ty1 >> bx2 >> by2 >> tx2 >> ty2;
	int ans = max(max(ty1,ty2)-min(by1,by2),max(tx1,tx2)-min(bx1,bx2));
	cout << ans * ans << endl;
	
	return 0;
}


