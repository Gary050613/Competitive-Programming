#include <bits/stdc++.h>
using namespace std;

int num[11], n;

void qsort(int left, int right){
	int i = left++;
	int j = right;
	int k = num[i];
	if(left >= right){
		return;
	}
	while(left < right){
		while(num[right] > k && left < right){
			right--;
		}
		while(num[left] < k && left < right){
			left++;
		}
		if(left < right){
			swap(num[left], num[right]);
		}
	}
	swap(num[left], num[i]);
	qsort(i,left-1);
	qsort(left+1,j);
}

int main(){

	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> num[i];
	}
	qsort(1, n);
	for(int i = 1;i<=n;i++){
		cout << num[i] << " ";
	}

	return 0;
}


