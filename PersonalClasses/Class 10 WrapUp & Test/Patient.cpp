#include <bits/stdc++.h>
using namespace std;

struct patient{
	string ID;
	int age;
} p[101];

bool compare(patient p1, patient p2){
	if(p1.age >= 60 && p2.age >= 60){
		if(p1.age > p2.age){
			return true;
		}
	}else if(p1.age >= 60 && p2.age < 60){
		return true;
	}
	return false;
}

int main(){
	
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> p[i].ID >> p[i].age;
	}
	sort(p,p+n,compare);
	for(int i = 0;i<n;i++){
		cout << p[i].ID << endl;
	}
	
	return 0;
}


