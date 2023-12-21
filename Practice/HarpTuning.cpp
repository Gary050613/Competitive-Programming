#include <bits/stdc++.h>
using namespace std;
string str, ch="", n="";
bool tune = 0, flag = 0;
int main(){
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='+') tune = 1;
        if(str[i]=='-') tune = 0;
        if(flag == 0 && isdigit(str[i])){
            flag = 1;
            n = "";
            n = n + str[i];
        }
        else if(flag == 1 && isdigit(str[i])) n = n + str[i];
        if(flag == 1 && isalpha(str[i])){
            if(tune == 1){
                cout << ch << " tighten " << n << endl;
            }else{
                cout << ch << " loosen " << n << endl;
            }
            ch = "";
            ch = ch + str[i];
            flag = 0;
        }else if(flag == 0 && isalpha(str[i])){
            ch = ch + str[i];
        }
    }
    if(tune == 1){
        cout << ch << " tighten " << n << endl;
    }else{
        cout << ch << " loosen " << n << endl;
    }
    return 0;
}
