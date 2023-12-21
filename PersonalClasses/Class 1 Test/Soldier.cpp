#include <bits/stdc++.h>
using namespace std;

int main(){
	int current = 0, energy, strength, power;
	cin >> energy >> strength >> power;
	while(power--) {
		current += strength;
		if(current >= energy) {
			current = 0;
			strength += energy / strength;
		}
	}
	cout << strength;
	return 0;
}

