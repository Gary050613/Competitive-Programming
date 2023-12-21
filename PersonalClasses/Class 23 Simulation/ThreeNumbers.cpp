#include <bits/stdc++.h>
using namespace std;
int used[10] = {0};

bool update(int n){
	while(n>0){
		int last = n%10;
		if(used[last]){
			return false;
		}else{
			used[last] = 1;
		}
		n/=10;
	}
	return true;
}

int main(){
	
	for(int a = 123;a<=329;a++){
		memset(used,0,sizeof(used));
		used[0] = 1;
		int b = a*2;
		int c = a*3;
		if(update(a)){
			if(update(b)){
				if(update(c)){
					cout << a << " " << b << " " << c << endl;
				}
			}
		}
	}
	
	return 0;
}


