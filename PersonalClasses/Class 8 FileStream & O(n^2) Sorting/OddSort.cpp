#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, a, ans[501] = {0}, len = 0, index = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a;
		if(a % 2 == 1){
			index = 0;
			while(a > ans[index] && index < len){
				index++;
			}
			len++;
			for(int j = len;j>index;j--){
				ans[j] = ans[j-1];
			}
			ans[index] = a;
		}
	}
	for(int i = 0;i<len;i++){
		if(i != len-1){
			cout << ans[i] << ", ";
		}else{
			cout << ans[i] << endl;
		}
	}

	return 0;
}


