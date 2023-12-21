/*
ID: gary0501
TASK: TASK_NAME_HERE
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct Rect{
    int x1, y1, x2, y2;
    int area(){return (x2-x1)*(y2-y1);}
}a, b;

bool covered(int x,int y,int x1,int y1,int x2,int y2){
    return x > x1 && x < x2 && y > y1 && y < y2;
}

int main(){

    setIO("billboard");
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int corners = covered(a.x1, a.y1, b.x1, b.y1, b.x2, b.y2)+
                  covered(a.x1, a.y2, b.x1, b.y1, b.x2, b.y2)+
                  covered(a.x2, a.y1, b.x1, b.y1, b.x2, b.y2)+
                  covered(a.x2, a.y2, b.x1, b.y1, b.x2, b.y2);
    if(corners < 2) cout << a.area() << endl;
    else if(corners == 4) cout << 0 << endl;
    else cout << a.area() - (min(a.x2, b.x2) - max(a.x1, b.x1))*(min(a.y2, b.y2) - max(a.y1, b.y1)) << endl;
    return 0;
}
