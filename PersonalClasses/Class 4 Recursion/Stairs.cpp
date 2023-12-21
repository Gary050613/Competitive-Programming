#include<iostream>
using namespace std;

int queue[1001];
int index;

void output(){
	for(int i=0;i<index;i++){
		cout << queue[i] << " ";
	}
	cout << endl;
} 

void step(int n){
	if(n == 0){
		output();
		return;
	}
	queue[index++] = 1;
	step(n-1); 
	--index;
	
	if(n > 1){
		queue[index++] = 2;
		step(n-2); 
		--index;
	}
	if(n > 2){
		queue[index++] = 3;
		step(n-3); 
		--index;
	}
}
int main(){

	int n;
	cin >> n;
	step(n);

	return 0;
}
