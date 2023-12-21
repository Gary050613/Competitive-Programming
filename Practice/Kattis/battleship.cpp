#include <bits/stdc++.h>
using namespace std;
char g1[31][31], g2[31][31]; int t, w, h, n, x, y, c1, c2, a=2, ans, termin=0;
int main(){
	cin >> t;
	while(t--){
		ans = 0, a = 2, termin = 0, c1 = 0, c2 = 0;
		cin >> w >> h >> n;
		for(int i = h-1;i>=0;i--){
			for(int j = 0;j<w;j++){
				cin >> g1[j][i];
				if(g1[j][i]=='#') c1++;
			}
		}
		for(int i = h-1;i>=0;i--){
			for(int j = 0;j<w;j++){
				cin >> g2[j][i];
				if(g2[j][i]=='#') c2++;
			}
		}
		while(n--){
			cin >> x >> y;
			if(!termin){
				if(a == 1){
					bool hit = false;
					if(g1[x][y] == '#'){
						c1--; g1[x][y] = '_';
						hit = true;
					}
					if(hit && c1 != 0) continue;
					else{
						a = 2;
						if(c1 == 0){
							if(ans == 1) ans = 0;
							else ans = 2;
							termin = 1;
						}
					}
				}else{
					bool hit = false;
					if(g2[x][y] == '#'){
						c2--; g2[x][y] = '_';
						hit = true;
					}
					if(hit && c2!=0) continue;
					else{
						a = 1; if(c2 == 0) ans = 1;
					}
				}
			}
		}
//		for(int i = h-1;i>=0;i--){
//			for(int j = 0;j<w;j++){
//				cout << g1[j][i];
//			}
//			cout << endl;
//		}
//		for(int i = h-1;i>=0;i--){
//			for(int j = 0;j<w;j++){
//				cout << g2[j][i];
//			}
//			cout << endl;
//		}
		if(ans == 1) cout << "player one wins\n";
		else if(ans == 2) cout << "player two wins\n";
		else cout << "draw\n";
	}
	return 0;
}


