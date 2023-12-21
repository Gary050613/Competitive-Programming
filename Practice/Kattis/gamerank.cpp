#include <bits/stdc++.h>
using namespace std;
string str; int level=25, curStar=0, acc=0; bool isLegend=false;
int req[26] = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
int main(){
	cin >> str;
	for(int i = 0;i<str.length();i++){
		if(str[i] == 'W'){
			if(level <= 25 && level >= 6 && acc >= 2) curStar++;
			curStar++;
			acc++;
			if(curStar > req[level] && level == 1) isLegend = 1;
			if(curStar > req[level]) curStar -= req[level--]; // Checks level up
		}else if(str[i] == 'L'){
			acc = 0;
			if(level >= 1 && level <= 20) curStar--;
			if(curStar < 0 && level >= 20) curStar = 0;
			else if(curStar < 0) curStar += req[++level];
		}
	}
	if(isLegend) cout << "Legend\n";
	else cout << level << endl;
	return 0;
}


