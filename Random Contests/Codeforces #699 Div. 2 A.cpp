#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, x, y, maxU = 0, maxD = 0, maxR = 0,maxL = 0;
	char s[100001];
	cin >> n;
	while(n--){
		maxU = 0, maxD = 0, maxR = 0,maxL = 0;
		cin >> x >> y >> s;
		int len = strlen(s);
		for(int i = 0;i<=len;i++){
			if(s[i] == 'U'){
				maxU++;
			}else if(s[i] == 'D'){
				maxD--;
			}else if(s[i] == 'R'){
				maxR++;
			}else if(s[i] == 'L'){
				maxL--;
			}
		}
		if(maxU >= y && maxD <= y && maxR >= x && maxL <= x){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	
	return 0;
}
