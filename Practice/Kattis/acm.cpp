#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, times[30]={0},ans=0,p=0;
	bool result[30]={0};
	char ch;
	string str;
	while(cin >> m && m != -1){
		cin >> ch >> str;
		if(result[ch-64]){
			continue;
		}
		if(str=="right"){
			result[ch-64] = 1;
			ans += times[ch-64]*20 + m;
		}else{
			times[ch-64]++;
		}
	}
	for(int i = 1;i<=30;i++){
		if(result[i]) p++;
	}
	cout << p << " " << ans << endl;
	return 0;
}


