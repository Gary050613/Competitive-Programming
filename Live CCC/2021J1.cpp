#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int temp;
	scanf("%d", &temp);
	int pressure = temp*5-400;
	printf("%d\n", pressure);
	if(pressure > 100){
		printf("-1\n");
	}else if(pressure < 100){
		printf("1\n");
	}else{
		printf("0\n");
	}
	
	return 0;
}


