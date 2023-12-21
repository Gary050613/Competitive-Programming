#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	bool end = false;
	cin >> n;
	int list[n], ans = 0;
	stack<int> s;
	for(int i = 0;i<n;i++){
		cin >> list[i];
	}
	for(int i = 0;i<n-1;i++){
		s = stack<int>();
		for(int j = i+1;j<n;j++){
			if(s.empty()){
				s.push(list[j]);
//				cout << list[i] << " " << list[j] << endl;
				ans++;
				if(list[j] > list[i]){
					j = n;
				}
			}else{
				if(list[i] >= list[j]){
					if(list[j] >= s.top()){
						s.push(list[j]);
						ans++;
					}
				}else{
					ans++;
					j = n;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}


