#include<iostream>
#define N 100001 
using namespace std;
int arr[N],ans;
void merge(int r[],int left,int right){
	if(left == right){
		return;
	}
	int mid = (left + right) / 2;
	merge(r,left,mid);
	merge(r,mid+1,right);
	int i = left,j = mid + 1, k = left;
	while(i <= mid && j <= right){
		if(arr[i] <= arr[j]){
			r[k++] = arr[i++];
		}
		else{
			r[k++] = arr[j++];
			ans += mid +1 -i;
		}
	}
	while(i <= mid) r[k++] = arr[i++];
	while(j <= right) r[k++] = arr[j++];
	for(int i = left; i <= right;i++){
		arr[i] = r[i];
	}
} 

int main(){

	/*
		a[i]:left 
		a[j]:mid + 1 
		
		????? ? a[i] ????? a[j] ?
		? a[j] ?? a[i] ???
		??????? mid+1-i 
		
	*/
	int n,r[100];
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	merge(r,1,n);
	cout << ans << endl;

	return 0;
}
