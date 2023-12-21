#include <bits/stdc++.h>
using namespace std;
// double rMass = 100000, vel = 4.32e8, d = 984000000, t = 0;
double G = 6.67e-11, M = 5.97e24, R = 6371000;
// Loses 2578 kg of mass for 6770000 N of thrust each second
double vel = -130, d = 984000000, t=0, aMass = 3.323e11;
double nOfT = 20;
double force = 6700000*nOfT; // F = ma

// GMm/r/r
bool flag;
double g(double m, double r){
    return G*M*m/r/r;
}
double f(double rMass){
    vel = -130, d = 984000000, t=0, aMass = 3.323e11;
    while(d <= 984000000){  
        if(rMass <= 8400*nOfT) return -1;
        t += 1.0;
        vel += (force-g(rMass+aMass, d))/(rMass+aMass);
        d += vel;
        rMass -= 2578*nOfT;
        if(flag && vel > 0){printf("Closest the asteroid will reach earth: %lf\n", d); flag = 0;}
    }
    return rMass;
}
int main(){
    // Binary Search
    double l = 1000, r = 100000000000;
    while(l<r){
        double mid = (l+r)/2;
        if(f(mid)==-1) l = mid;
        else r = mid;
        if(abs(l-r)<1) break;
    }
    flag = 1;
    f(l);
    printf("Initial Mass: %lf\n", l);
    printf("Time needed: %lf", t);
    // printf("Initial Velocity: %lf\nInitial Mass: %lf\nTime Needed: %lf", vel, rMass, t);
    return 0;
}