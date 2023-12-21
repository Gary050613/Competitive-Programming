#include <bits/stdc++.h>
using namespace std;

int train[10001], ans=0;

void msort(int r[], int left, int right){
	if(left == right){
		return;
	}
	int mid = (left + right) / 2;
	int i = left;
	int j = mid+1;
	int k = left;
	msort(r, left, mid);
	msort(r, mid+1, right);
	while(i <= mid && j <= right){
		if(train[i] > train[j]){
			r[k++] = train[j++];
			ans++;
		}else{
			r[k++] = train[i++];
		}
	}
	while(i<=mid){
		r[k++] = train[i++];
	}
	while(j<=right){
		r[k++] = train[j++];
	}
	for(int i = left;i<=right;i++){
		train[i] = r[i];
	}
}

int main(){
	
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> train[i];
	}
	for(int i = 0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			if(train[i] > train[j]){
				ans++;
			}
		}
	}
//	int r[n];
//	msort(r, 0, n-1);
	cout << ans << endl;
	
	return 0;
}


