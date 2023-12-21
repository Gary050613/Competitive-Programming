#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int canons[1001], h, count = 1;
	memset(canons, 999999, sizeof(canons));
	while(scanf("%d", &h) != EOF){
		for(int i = 0;i<count;i++){
			if(canons[i] > h){
				canons[i] = h;
				break;
			}
			if(i == count-1){
				canons[count] = h;
				count++;
				break;
			}
		}
		sort(canons, canons+count);
	}
	cout << count << endl;
	return 0;
}
/*
389 207 155 300 299 170 158 65
*/

