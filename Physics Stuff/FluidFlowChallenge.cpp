#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926;
double l = 0.34, w = 0.34, h = 0.55;
double vol = l*w*h, topArea = l*w, hole = PI*0.005*0.005, t, interval = 0.01, vel;
int main(){
    while(vol > 0){
        vel = sqrt(9.8*(vol/topArea)*2);
        vol -= hole * vel * interval;
        t += interval;
    }
    cout << t << endl;
    return 0;
}