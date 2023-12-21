#include <bits/stdc++.h>
using namespace std;
int a[101];
void qsort(int left, int right){
	if(left >= right) return;
	int i = left;
	int j = right;
	int x = a[left];
	while(i < j){
		while(i < j && x <= a[j]){
			j++;
			a[i] = a[j];
		}
		while(i < j && x >=a[i]){
			i++;
			a[j] = a[i];
		}
	}
	a[i] = x;
	qsort(left,i-1);
	qsort(i+1,right);
}

int main(){
	
	
	
	return 0;
}


