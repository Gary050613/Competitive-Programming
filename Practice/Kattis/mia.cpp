#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d, v1, v2;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) && (a || b || c || d)){
		if(a+b==3 && c+d==3) cout << "Tie.\n";
		else if(a+b==3) cout << "Player 1 wins.\n";
		else if(c+d==3) cout << "Player 2 wins.\n";
		else if(a == b && c == d){
			if(a > c) cout << "Player 1 wins.\n";
			else if(a < c) cout << "Player 2 wins.\n";
			else cout << "Tie.\n";
		}else if(a == b) cout << "Player 1 wins.\n";
		else if(c == d) cout << "Player 2 wins.\n";
		else{
			if(a > b) v1 = a*10+b;
			else v1 = b*10+a;
			if(c > d) v2 = c*10+d;
			else v2 = d*10+c;
			if(v1 > v2) cout << "Player 1 wins.\n";
			else if(v1 < v2) cout << "Player 2 wins.\n";
			else cout << "Tie.\n";
		}
	}
	return 0;
}


