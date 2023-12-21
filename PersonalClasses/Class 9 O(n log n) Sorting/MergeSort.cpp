#include <bits/stdc++.h>
using namespace std;

int num[5000001];

void merge(int r[],int left,int right){
	if(left == right) return;
	int mid = (left + right)/2;
	merge(r,left,mid);
	merge(r,mid+1,right);
	
	int i  = left, j = mid +1, k = left;
	while( i <= mid && j <= right){
		if(num[i]<= num[j]){
			r[k++] = num[i++];
		}
		else{
			r[k++] = num[j++];
		}
	}
	while(i <= mid) r[k++] = num[i++];
	while(j <= right) r[k++] = num[j++];
	for(int i = left; i <= right;i++){
		num[i] = r[i];
	}
}

int main(){

	int n, k;
	cin >> n >> k;
	int num[n];
	for(int i = 0;i<n;i++){
		cin >> num[i];
	}
	

	return 0;
}


