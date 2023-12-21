#include <bits/stdc++.h>
using namespace std;

struct node{
	int value;
	int left, right;
} tree[101];

int e[101][101];

void create(int i){
	if(i == 0){
		return;
	}
	int v, l, r;
	cin >> v >> l >> r;
	tree[i].value = v;
	tree[i].left = l;
	tree[i].right = r;
}

int main(){

	int n, v, l, r;
	cin >> n;
	for(int i = 1;i<=n;i++){
		create(i);
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i == j){
				e[i][j] = 0;
			}else{
				e[i][j] = 999999;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(tree[i].left!=0){
			e[i][tree[i].left] = 1;
			e[tree[i].left][i] = 1;
//			e[i][tree[i].left] = tree[i].value;
//			e[tree[i].left][i] = tree[tree[i].left].value;
		}
		if(tree[i].right!=0){
			e[i][tree[i].right] = 1;
			e[tree[i].right][i] = 1;
//			e[i][tree[i].right] = tree[i].value;
//			e[tree[i].right][i] = tree[tree[i].right].value;
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(e[i][j] > e[i][k] + e[k][j]){
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}
	int sum[n+1] = {0};
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			sum[j] += e[i][j] * tree[i].value;
//			cout << e[i][j] << " ";
		}
//		cout << endl;
	}
	int min = INT_MAX;
	for(int i = 1;i<=n;i++){
		if(min > sum[i]){
			min = sum[i];
		}
	}
	cout << min;
	return 0;
}


