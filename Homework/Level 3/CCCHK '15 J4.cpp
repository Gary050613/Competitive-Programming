#include <bits/stdc++.h>
using namespace std;
bool occupied[1000000001]={0};
int main(){
	
	int length, n, a, b, ans = 0;
	cin >> length >> n;
	while(n--){
		cin >> a >> b;
		for(int i = a;i<=b-1;i++){
			occupied[i] = 1;
		}
	}
//	for(int i = 0;i<=length-1;i++){
//		cout << occupied[i] << " ";
//	}
//	cout << endl;
	int temp = 0;
	for(int i = 0;i<=length-1;i++){
		if(occupied[i]==0){
			temp++;
		}else{
			ans = max(ans, temp);
			temp = 0;
		}
	}
	ans = max(ans,temp);
	cout << ans << endl;
	
	return 0;
}


