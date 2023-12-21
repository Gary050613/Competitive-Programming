#include <bits/stdc++.h>
using namespace std;

int chi[301], sum[301], num[301];

void qsort(int left, int right, int arr[]){
	int i=left, j=right, k=arr[left];
	if(i >= j){
		return;
	}
	while(i < j){
		while(arr[j] > k && i < j){
			j--;
		}
		while(arr[i] < k && i < j){
			i++;
		}
		if(i < j){
			swap(arr[i], arr[j]);
			swap(num[i], num[j]);
		}
	}
	swap(arr[left],arr[i]);
	swap(num[left], num[i]);
	qsort(left, i-1, arr);
	qsort(i+1,right, arr);
}

int main(){

	int n, a, b;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> chi[i] >> a >> b;
		sum[i] = chi[i] + a + b;
		num[i] = i;
	}
	qsort(1,n,sum);
	for(int i = 1;i<=5;i++){
		cout << num[i] << " " << sum[i] << endl;
	}

	return 0;
}


