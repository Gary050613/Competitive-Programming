#include <bits/stdc++.h>
using namespace std;
int pre, t, n, ans=0; string cmd, str;
int main(){
	while(cin >> str >> t && str != "0" && t){
        ans=0;
		if(str.substr(0,2) == "0x"){
			pre = stoi(str, nullptr, 16);
		}else if(str[0] == '0'){
            pre = stoi(str.substr(1,str.length()-1), nullptr, 8);
		}else{
            pre = stoi(str);
		}
		while(t--){
            cin >> cmd >> n;
            if(cmd == "i++"){
            	if(n == pre) ans++;
            	pre = n+1;
			}else if(cmd == "++i"){
				if(n == pre+1) ans++;
				pre = n;
			}else if(cmd == "i--"){
				if(n == pre) ans++;
				pre = n-1;
			}else if(cmd == "--i"){
				if(n == pre-1) ans++;
				pre = n;
			}else if(cmd == "i"){
				if(n == pre) ans++;
				pre = n;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


