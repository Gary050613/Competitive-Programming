#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n,a[101],b[101],ans,i;
void initial(int a[]){
	string s;
	cin >> n >> s;
	a[0] = s.length();
	for(int i = 1;i <= a[0]; i++){
		if(s[a[0] - i] >= '0' && s[a[0]-i] <= '9'){
			a[i] = s[a[0] - i] - '0';
		}
		else{
			a[i] = s[a[0] - i] - 'A' + 10;
		}
	}
}
void Add(int a[])
{
	b[0] = a[0];
	for(int i = 1; i <= a[0]; i++){
		b[i] = a[a[0] - i +1];
	}
	//?1??,??????? 
	for(int i = 1; i <= a[0]; i++){
		a[i] += b[i];
	}
	// ??
	for(int i =1; i <= a[0]; i++){
		//??,???? 
		a[i+1] += a[i] / n;
		a[i] %= n;
	} 
	if(a[a[0]+1]!=0){
		a[0]++;
	}
}
bool judge(int a[]){
	for(int i = 1; i <= a[0]; i++){
		if(a[i] != a[a[0] - i +1]){
			return false;
		}
	}
	return true;
}
int main(){

	initial(a);
	if(judge(a)){
		cout << 0 << endl;
		return 0;
	}
	ans = 0;
	while(ans <= 30){
		ans++;
		Add(a);
		if(judge(a)){
			cout << ans << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;

	return 0;
}
