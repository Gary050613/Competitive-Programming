#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		string Jane, John, JaneP="", JohnP="";
		cin >> Jane >> John;
		for(int i = 0;i<1001;i++){
			if(i==1000){
				cout << "Keeps going and going ...\n";
				break;
			}
			if(Jane.empty()){
				if(JaneP.empty()){
					cout << "John wins.\n";
					break;
				}else{
					reverse(JaneP.begin(), JaneP.end());
					Jane = JaneP;
					JaneP = "";
				}
			}
			if(John.empty()){
				if(JohnP.empty()){
					cout << "Jane wins.\n";
					break;
				}else{
					reverse(JohnP.begin(), JohnP.end());
					John = JohnP;
					JohnP = "";
				}
			}
			JaneP = Jane[0]+JaneP;
			JohnP = John[0]+JohnP;
			Jane = Jane.substr(1,Jane.length()-1);
			John = John.substr(1,John.length()-1);
			if(JaneP[0]==JohnP[0]){
				if(random() / 141 % 2){
					JohnP = JaneP+JohnP;
					JaneP = "";
					cout << "Snap! for John: " << JohnP << endl;
				}else{
					JaneP = JohnP+JaneP;
					JohnP = "";
					cout << "Snap! for Jane: " << JaneP << endl;
				}
			}
		}
		if(T>0) cout << endl;
	}
	return 0;
}


