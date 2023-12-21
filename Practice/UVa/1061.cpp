#include <bits/stdc++.h>
using namespace std;
string p1, p2, c, types[8]={"O-", "O+", "AB-", "AB+", "B-", "B+", "A-", "A+"}; int cnt=1; vector<string> vec;

bool check(string str){
    // Check ABO allele
    if(str[1]=='B'){
        if(p1[0] == 'O' || p2[0]=='O' || (p1[0]==p2[0] && p1[1]!='B' && p2[1]!='B')) return false;
    }else if(str[0]=='O'){
        if(p1.substr(0,2)=="AB"||p2.substr(0,2)=="AB") return false;
    }else if(str[0]=='A'){
        if(!(p1[0]=='A'||p2[0]=='A')) return false;
    }else if(str[0]=='B'){
        if(!(p1[0]=='B'||p2[0]=='B'||p1[1]=='B'||p2[1]=='B')) return false;
    }
    // Check Rh
    if(str[str.length()-1]=='+'){
        if(p1[p1.length()-1]=='-' && p2[p2.length()-1]=='-') return false;
    }
    return true;
}

bool check1(string str){
    // Check ABO allele
    if(c[1]=='B'){
        if(str[0] == 'O' || p2[0]=='O' || (str[0]==p2[0] && str[1]!='B' && p2[1]!='B')) return false;
    }else if(c[0]=='O'){
        if(str.substr(0,2)=="AB"||p2.substr(0,2)=="AB") return false;
    }else if(c[0]=='A'){
        if(!(str[0]=='A'||p2[0]=='A')) return false;
    }else if(c[0]=='B'){
        if(!(str[0]=='B'||p2[0]=='B'||str[1]=='B'||p2[1]=='B')) return false;
    }
    // Check Rh
    if(c[c.length()-1]=='+'){
        if(str[str.length()-1]=='-' && p2[p2.length()-1]=='-') return false;
    }
    return true;
}

bool check2(string str){
    // Check ABO allele
    if(c[1]=='B'){
        if(p1[0] == 'O' || str[0]=='O' || (p1[0]==str[0] && p1[1]!='B' && str[1]!='B')) return false;
    }else if(c[0]=='O'){
        if(p1.substr(0,2)=="AB"||str.substr(0,2)=="AB") return false;
    }else if(c[0]=='A'){
        if(!(p1[0]=='A'||str[0]=='A')) return false;
    }else if(c[0]=='B'){
        if(!(p1[0]=='B'||str[0]=='B'||p1[1]=='B'||str[1]=='B')) return false;
    }
    // Check Rh
    if(c[c.length()-1]=='+'){
        if(p1[p1.length()-1]=='-' && str[str.length()-1]=='-') return false;
    }
    return true;
}

int main(){
    while(cin >> p1 >> p2 >> c && (p1!="E"&&p2!="N"&&c!="D")){
        vec.clear();
        if(c == "?"){
            for(int i = 0;i<8;i++){
                if(check(types[i])) vec.push_back(types[i]);
            }
        }else{
            for(int i = 0;i<8;i++){
                if(p1=="?") if(check1(types[i])) vec.push_back(types[i]);
                if(p2=="?") if(check2(types[i])) vec.push_back(types[i]);
            }
        }
        if(vec.empty()){
            if(p1 == "?") p1 = "IMPOSSIBLE";
            else if(p2 == "?") p2 = "IMPOSSIBLE";
            else c = "IMPOSSIBLE";
            printf("Case %d: ", cnt++); cout << p1 << " " << p2 << " " << c << endl;
        }else if(vec.size()==1){
            if(p1 == "?") p1 = vec[0];
            else if(p2 == "?") p2 = vec[0];
            else c = vec[0];
            printf("Case %d: ", cnt++); cout << p1 << " " << p2 << " " << c << endl;
        }else{
            printf("Case %d: ", cnt++);
            if(p1=="?"){
                cout << "{" << vec[0];
                for(int i = 1;i<vec.size();i++) cout << ", " << vec[i];
                cout << "}";
            }else cout << p1;
            cout << " ";
            if(p2=="?"){
                cout << "{" << vec[0];
                for(int i = 1;i<vec.size();i++) cout << ", " << vec[i];
                cout << "}";
            }else cout << p2;
            cout << " ";
            if(c=="?"){
                cout << "{" << vec[0];
                for(int i = 1;i<vec.size();i++) cout << ", " << vec[i];
                cout << "}";
            }else cout << c;
            cout << "\n";
        }
    }
    return 0;
}