#include <bits/stdc++.h>
using namespace std;
char g[4][4]; 

char check(){
	bool Xwin = false, Owin = false;
	bool Xw = true, Ow = true;
	for(int i = 1;i<=3;i++){
		Xw = true, Ow = true;
		for(int j = 1;j<=3;j++){
			if(g[i][j] != 'X') Xw = false;
			if(g[i][j] != 'O') Ow = false;
		}
		if(Xw) Xwin = true;
		if(Ow) Owin = true;
		Xw = true, Ow = true;
		for(int j = 1;j<=3;j++){
			if(g[j][i] != 'X') Xw = false;
			if(g[j][i] != 'O') Ow = false;
		}
		if(Xw) Xwin = true;
		if(Ow) Owin = true;
	}
	Xw = true; Ow = true;
	for(int i = 1;i<=3;i++){
		if(g[i][i] != 'X') Xw = false;
		if(g[i][i] != 'O') Ow = false;
	}
	if(Xw) Xwin = true;
	if(Ow) Owin = true;
	Xw = true; Ow = true;
	for(int i = 1;i<=3;i++){
		if(g[4-i][i] != 'X') Xw = false;
		if(g[4-i][i] != 'O') Ow = false;
	}
	if(Xw) Xwin = true;
	if(Ow) Owin = true;
	if(Xwin && Owin) return 'B';
	else if(Xwin) return 'X';
	else if(Owin) return 'O';
	else return 'N';
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int O, X;
		O = 0, X = 0;
		for(int i = 3;i>=1;i--){
			for(int j = 1;j<=3;j++){
				cin >> g[i][j];
				if(g[i][j] == 'O') O++;
				else if(g[i][j] == 'X') X++;
			}
		}
		char res = check();
		// If more O than X at anytime || More than 1 XO diff
		if(O > X || X-O>1 || res == 'B' || (res=='X'&&X-O!=1) || (res=='O'&&X!=O)){
			cout << "no\n";
//			cout << res << endl;
//			cout << X << endl << O << endl;
		}else{
			cout << "yes\n";
		}
	}
	return 0;
}


