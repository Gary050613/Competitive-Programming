#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream cin("billboard.in");
	ofstream cout("billboard.out");
	int bx, by, tx, ty, bx1, by1, tx1, ty1, bx2, by2, tx2, ty2;
	cin >> bx1 >> by1 >> tx1 >> ty1;
	cin >> bx2 >> by2 >> tx2 >> ty2;
	cin >> bx >> by >> tx >> ty;
	int area1 = (tx1-bx1)*(ty1-by1);
	int area2 = (tx2-bx2)*(ty2-by2);
	int Overlap1 = max(0,min(tx,tx1)-max(bx,bx1)) * max(0,min(ty,ty1)-max(by,by1));
	int Overlap2 = max(0,min(tx,tx2)-max(bx,bx2)) * max(0,min(ty,ty2)-max(by,by2));
	int ans = area1 + area2 - Overlap1 - Overlap2;
//	cout << area1 << endl << area2 << endl << (min(tx1, tx)-max(bx,bx1))*(min(ty1, ty)-max(by1, by)) << endl << (min(tx, tx2)-max(bx,bx2)*(min(ty2,ty)-max(by2,by))) << endl;
	cout << ans << endl;
	
	return 0;
}


