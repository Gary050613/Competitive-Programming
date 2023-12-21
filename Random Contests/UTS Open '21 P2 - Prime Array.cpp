#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, arr[101], largestP = 2, len = 1;

bool isPrime(ll a){
	for(int i = 2;i<=sqrt(a);i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

int nextPrime(){
	while(largestP++){
		if(isPrime(largestP)){
			break;
		}
	}
	return largestP;
}

int main(){
	
	cin >> k; // 4
	arr[1] = 2;
	while(k != 0){
		if(k >= len){
			k -= len;
			arr[++len] = nextPrime();
		}else{
			int result = 2;
			for(int i = 1;i<=len-k;i++){
				result *= arr[i];
			}
			k = 0;
			arr[++len] = result;
		}
	}
	cout << len << endl;
	for(int i = 1;i<=len;i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}


