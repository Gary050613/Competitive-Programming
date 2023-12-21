#include <bits/stdc++.h>
using namespace std;

char chars[101];

double calc(){
	cin >> chars;
	switch(chars[0]){
		case '+':
			return calc() + calc();
		case '-':
			return calc() - calc();
		case '*':
			return calc() * calc();
		case '/':
			return calc() / calc();
		default:
			return atof(chars);
			break;
	}
}

int main(){
	double n = calc();
	printf("%f\n", n);

	return 0;
}

