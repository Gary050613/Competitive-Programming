#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t, n;
	cin >> t;
	while(t--){
		stack<int> s;
		int count = 1;
		cin >> n;
		int a[n+1];
		for(int i = n;i>0;i--){
			cin >> a[i];
		}
		for(int i = 1;i<=n;i++){
			if(a[i] == count){
				count++;
			}else{
				s.push(a[i]);
			}
			while(!s.empty() && s.top() == count){
				s.pop();
				count++;
			}
		}
		if(s.empty()){
			cout << 'Y' << endl;
		}else{
			cout << 'N' << endl;
		}
	}
	
	return 0;
}


