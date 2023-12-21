#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
struct node{
	char value;
	int left, right;
} data[101];

void create(int i){
	char ch;
	cin >> ch;
	if(ch == '.'){
		data[i].value = ch;
		return;
	}
	data[i].value = ch;
	data[i].left = i*2;
	data[i].right = i*2+1;
	create(data[i].left);
	create(data[i].right);
}

void middleFirst(int i){
	if(data[i].value == '.'){
		return;
	}
	middleFirst(data[i].left);
	cout << data[i].value;
	middleFirst(data[i].right);
}

void lastFirst(int i){
	if(data[i].value == '.'){
		return;
	}
	lastFirst(data[i].left);
	lastFirst(data[i].right);
	cout << data[i].value;
} 

int main(){

	create(1);
	middleFirst(1);
	cout << endl;
	lastFirst(1);
	return 0;
}


