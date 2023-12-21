#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, arr[101], ans = 0;
	scanf("%d", &n);
	for(int i = 1;i<=n;i++){
		scanf("%d", &arr[i]);
	}
	sort(arr+1, arr+1+n);
	for(int i = 3;i<=n;i++){
		for(int j = 1;j<i-1;j++){
			for(int k = j+1;k<i;k++){
				if(arr[i] == arr[j]+arr[k] && j != k){
					ans++;
					j = i;
					k = i;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}


