#include <bits/stdc++.h>
using namespace std;
int n, arr[1001], prevD[1001];
string str;
void shuffle(){
	if(str == "out"){
		for(int i = 1;i<=n;i++){
			if(i%2==1){
				arr[i]=prevD[(i+1)/2];
			}else{
				arr[i]=prevD[(i)/2+(n+1)/2];
			}
		}
		for(int i = 1;i<=n;i++){
			prevD[i]=arr[i];
		}
	}else{
		for(int i = 1;i<=n;i++){
			if(i%2==1){
				arr[i]=prevD[(i+1)/2+n/2];
			}else{
				arr[i]=prevD[(i)/2];
			}
		}
		for(int i = 1;i<=n;i++){
			prevD[i]=arr[i];
		}
	}
}
int main(){
	
	cin >> n >> str;
	for(int i = 1;i<=n;i++){
		prevD[i] = i;
	}
	int ans=0, flag=1;
	while(1){
		flag=1;
		shuffle();
		ans++;
		for(int i = 1;i<=n;i++){
			if(prevD[i]!=i){
				flag=0;
				break;
			}
		}
		if(flag) break;
	}
	cout << ans << endl;
	return 0;
}


