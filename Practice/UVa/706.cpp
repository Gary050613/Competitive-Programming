#include <bits/stdc++.h>
using namespace std;
int s; string in; set<int> tp, tl, tr, md, bl, br, bm;

void printT(){
    cout << " ";
    for(int i = 0;i<s;i++) cout << "-";
    cout << " ";
}

void printE(){
    for(int i = 0;i<s+2;i++) cout << " ";
}

void printL(){
    cout << "|";
    for(int i = 0;i<s/2;i++) cout << " ";
}

void printLE(){
    cout << " ";
    for(int i = 0;i<s/2;i++) cout << " ";
}

void printR(){
    for(int i = 0;i<(s+1)/2;i++) cout << " ";
    cout << "|";
}

void printRE(){
    for(int i = 0;i<(s+1)/2;i++) cout << " ";
    cout << " ";
}

int main(){
    tp.insert(0);
    tp.insert(2);
    tp.insert(3);
    tp.insert(5);
    tp.insert(6);
    tp.insert(7);
    tp.insert(8);
    tp.insert(9);

    tl.insert(0);
    tl.insert(4);
    tl.insert(5);
    tl.insert(6);
    tl.insert(8);
    tl.insert(9);

    tr.insert(0);
    tr.insert(1);
    tr.insert(2);
    tr.insert(3);
    tr.insert(4);
    tr.insert(7);
    tr.insert(8);
    tr.insert(9);

    md.insert(2);
    md.insert(3);
    md.insert(4);
    md.insert(5);
    md.insert(6);
    md.insert(8);
    md.insert(9);

    bl.insert(0);
    bl.insert(2);
    bl.insert(6);
    bl.insert(8);
    
    br.insert(0);
    br.insert(1);
    br.insert(3);
    br.insert(4);
    br.insert(5);
    br.insert(6);
    br.insert(7);
    br.insert(8);
    br.insert(9);

    bm.insert(0);
    bm.insert(2);
    bm.insert(3);
    bm.insert(5);
    bm.insert(6);
    bm.insert(8);
    bm.insert(9);
    while(cin >> s >> in && (s||in!="0")){
        for(int i = 0;i<2*s+3;i++){
            for(int j = 0;j<in.length();j++){
                int cur = in[j]-'0';
                if(i == 0){
                    if(tp.count(cur)) printT();
                    else printE();
                }else if(i == s+1){
                    if(md.count(cur)) printT();
                    else printE();
                }else if(i == 2*s+2){
                    if(bm.count(cur)) printT();
                    else printE();
                }else if(i > 0 && i < s+1){
                    if(tl.count(cur)) printL();
                    else printLE();
                    if(tr.count(cur)) printR();
                    else printRE();
                }else if(i>s+1 && i<s+s+2){
                    if(bl.count(cur)) printL();
                    else printLE();
                    if(br.count(cur)) printR();
                    else printRE();
                }
                if(j == in.length()-1) cout << "\n";
                else cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}