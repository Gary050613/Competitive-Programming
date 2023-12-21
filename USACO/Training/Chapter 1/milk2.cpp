/*
ID: gary0501
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
const int l = 1e6+5;
bool arr[l]={0};
int main(){
	
	ofstream cout("milk2.out");
	ifstream cin("milk2.in");
	
	int N, a, b, start=1e6+5, end=0, ans1=0, ans2=0;
	cin >> N;
	while(N--){
		cin >> a >> b;
		for(int i = a;i<b;i++){
			arr[i] = 1;
		}
		start = min(start, a);
		end = max(end, b);
	}
	int flag=1, c1=0, c2=0;
	for(int i = start;i<end;i++){
		if(arr[i] && flag) c1++;
		else if(!arr[i] && !flag) c2++;
		else if(arr[i] && !flag){
			flag=1;
			ans2 = max(ans2, c2);
			c2=0;
			c1++;
		}else if(!arr[i] && flag){
			flag=0;
			ans1 = max(ans1, c1);
			c1=0;
			c2++;
		}
	}
	ans1=max(ans1, c1);
	ans2=max(ans2, c2);
	cout << ans1 << " " << ans2 << endl;
	return 0;
}


