#include <bits/stdc++.h>
using namespace std;

struct{
	string name;
	int age, year;
} ppl[101];

int main(){
	
	int n, len = 1, base = 0, cur, baseYear, diff;
	ppl[0].name = "Bessie";
	ppl[0].age = 0;
	ppl[0].year = 0;
	string str, name1, condition, year1, name2; 
	string cycle[12]={"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
	cin >> n;
	while(n--){
		cin >> name1;
		cin >> str;
		cin >> str;
		cin >> condition;
		cin >> year1;
		for(int i = 0;i<12;i++){
			if(year1 == cycle[i]){
				cur = i;
			}
		}
		cin >> str;
		cin >> str;
		cin >> name2;
		for(int i = 0;i<len;i++){
			if(ppl[i].name == name2){
				base = ppl[i].age;
				baseYear = ppl[i].year;
				break;
			}
		}
		if(condition == "previous"){
			if(baseYear < cur){
				diff = baseYear+12-cur;
			}else if(baseYear > cur){
				diff = baseYear - cur;
			}else{
				diff = 12;
			}
			ppl[len].name = name1;
			ppl[len].year = cur;
			ppl[len++].age = base-diff;
		}else{
			if(baseYear < cur){
				diff = cur-baseYear;
			}else if(baseYear > cur){
				diff = cur+12-baseYear;
			}else{
				diff = 12;
			}
			ppl[len].name = name1;
			ppl[len].year = cur;
			ppl[len++].age = base+diff;
		}
//		cout << name1 << " " << condition << " " << year << " " << name2 << endl;
	}
	for(int i = 0;i<len;i++){
		if(ppl[i].name == "Elsie"){
			cout << abs(ppl[i].age) << endl;
			break;
		}
	}
	
	return 0;
}


