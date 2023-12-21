// DISGUSTING QUESTION. ALGO WAS CORRECT, DETECTING WIDTH METHOD WRONG
#include <bits/stdc++.h>
using namespace std;
const int MM = 155;
int m, in[MM], error=0, t=1, C, K; string v, code; map<string, char> mp;

int w(char ch){
    if(ch == '-') return 10;
    else return ch-'0';
}

int main(){
    mp["000010"]='0';
    mp["100010"]='1';
    mp["010010"]='2';
    mp["110000"]='3';
    mp["001010"]='4';
    mp["101000"]='5';
    mp["011000"]='6';
    mp["000110"]='7';
    mp["100100"]='8';
    mp["100000"]='9';
    mp["001000"]='-';
    while(cin >> m && m){
        error = 0;
        memset(in, 0, sizeof(in)); v=""; code="";
        int wide=0, thin=201;
        for(int i = 0;i<m;i++){
            cin >> in[i];
            wide=max(wide, in[i]); thin=min(thin, in[i]);
        }
        double mid = (wide+thin)/2.0;
        printf("Case %d: ", t++);
        if ((m + 1) % 6 != 0 || (m+1)/6 < 5) {
            cout << "bad code" << endl;
            continue;
        }
        // Check width
        wide = 0, thin = 501;
        for (int i = 0; i < m; i++) {
            int a = 0;
            if (in[i] < mid)
                a = in[i] * 2;
            else
                a = in[i];
            wide = max(wide, a), thin = min(thin, a);
        }
        if(wide*95>thin*105) {cout << "bad code\n"; continue;}
        // Translate input into 1 & 0
        for(int i = 0;i<m;i++){
            if(in[i] < mid) v.push_back('0');
            else v.push_back('1');
            // OG Method
            // if(in[i]>=thin && in[i]<=floor((double)thin*21/19)) v.push_back('0');
            // else if(in[i]>=ceil((double)wide*19/21) && in[i]<=wide) v.push_back('1');
        }
        // Fix orientation
        if(v[1]=='1') reverse(v.begin(), v.end());
        // Checks Start
        if(v.substr(0, 6) != "001100"){cout << "bad code\n"; continue;}
        v = v.substr(6);
        // Decode
        m = m+1-6-6;
        while(m>0){
            string cur = v.substr(0,6);
            if(mp.count(cur)) code.push_back(mp[cur]);
            else{error = 1; break;}
            m-=6;
            v=v.substr(6);
        }
        if(error){cout << "bad code\n"; continue;}
        // Checks End
        if(v != "00110"){cout << "bad code\n"; continue;}
        // Extracts C & K
        // if(!isdigit(code[code.length()-2])){cout << "bad C\n"; continue;}
        // if(!isdigit(code[code.length()-1])){cout << "bad K\n"; continue;}
        C = w(code[code.length()-2]);
        K = w(code[code.length()-1]);
        code = code.substr(0, code.length()-2);
        int curC=0, curK=0, len = code.length();
        for(int i = 1;i<=len;i++){
            curC += ((len-i)%10+1)*w(code[i-1]);
            curK += ((len-i+1)%9+1)*w(code[i-1]);
        }
        curC %= 11;
        if(curC != C) cout << "bad C\n";
        else{
            curK = (curK + C)%11;
            if(curK != K) cout << "bad K\n";
            else cout << code << endl;
        }
    }
    return 0;
}