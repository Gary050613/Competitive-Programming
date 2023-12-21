#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	while(cin >> n && n){
		printf("Printing order for %d pages:\n", n);
		if(n==1){
			printf("Sheet 1, front: Blank, 1\n");
			continue;
		}
		int t = (n-1)/4+1;
		int ext = t*4-n;
		for(int i = 1;i<=t;i++){
			if(ext>0){
				printf("Sheet %d, front: Blank, %d\n", i, i*2-1);
				ext--;
			}else{
				printf("Sheet %d, front: %d, %d\n", i, t*4+1-(i*2-1), i*2-1);
			}
			if(ext>0){
				printf("Sheet %d, back : %d, Blank\n", i, i*2);
				ext--;
			}else{
				printf("Sheet %d, back : %d, %d\n", i, i*2, t*4+1-(i*2));
			}
		}
	}
	return 0;
}


