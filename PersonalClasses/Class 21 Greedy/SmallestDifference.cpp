#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int t,n;
int a[15];
int work1(){
	int s1= 0,s2 = 0;
	int t = 1;
	while(a[t] == 0) t++;
	swap(a[1],a[t]);
	for(int i = 1; i <= (n+1)/2;i++) s1 = s1* 10 + a[i];
	for(int i = n; i >= n/2+2;i--) s2 = s2* 10 + a[i];
	return abs(s1-s2);
}
int work2(){
	long long s1,s2,ans = (1<<30)-1;
	bool judge[15];
	for(int i = 2; i <= n; i++){
		if(a[i-1]){
			s2 = a[i-1];
			s1 = a[i];
			int l = 1,r = n;
			memset(judge,false,sizeof(judge));
			judge[i-1] = judge[i] = true;
			for(int j = 1; j <= (n-2)/2; j++){
				while(judge[l]) l++;
				while(judge[r]) r--;
				judge[l] = judge[r] = true;
				s1 = s1 * 10 + a[l];
				s2 = s2 * 10 + a[r];
			}
			ans = min(ans,abs(s1-s2));
		}
	}
	return ans;
}
int main(){

	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n;i++){
			cin >> a[i];
		}
		sort(a+1,a+1+n);
		if(n == 2){
			cout << a[2] - a[1] << endl;
			continue;
		}
		if(n%2 == 1){
			cout << work1() << endl;
		}
		else{
			cout << work2() << endl;
		}
	}

	return 0;
}
