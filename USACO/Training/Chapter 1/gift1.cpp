/*
ID: gary0501
TASK: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

	ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	
	int NP, NG, money, index, rindex;
	string name, giver;
	fin >> NP;
	string names[NP];
	int bank[NP]={};
	for(int i = 0;i<NP;i++) {
		fin >> names[i];
	}
	for(int i = 0;i<NP;i++) {
		fin >> giver >> money >> NG;
		for(int j = 0;j<NP;j++){
			if(giver == names[j]){
				index = j;
				j=NP;
			}
		}
		if(NG != 0){
			for(int j = 0;j<NG;j++) {
				fin >> name;
				for(int k = 0;k<NP;k++){
					if(name == names[k]){
						rindex = k;
						k = NP;
					}
				}
				bank[rindex] += money/NG;
			}
			bank[index] += money%NG-money;
		}
		
	}
	for(int i = 0;i<NP;i++){
		fout << names[i] << " " << bank[i] << endl;
	}
	
	return 0;
}

