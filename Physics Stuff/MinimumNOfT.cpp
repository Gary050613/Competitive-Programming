#include <bits/stdc++.h>
using namespace std;
// double rMass = 100000, vel = 4.32e8, d = 984000000, t = 0;
double G = 6.67e-11, M = 5.97e24, R = 6371000;
// Loses 2578 kg of mass for 6770000 N of thrust each second
double vel = -130, d = 984000000, t=0, aMass = 3.323e11;
double nOfT = 1;
double force = 6700000*nOfT; // F = ma

// GMm/r/r
bool flag;
double g(double m, double r){
    return G*M*m/r/r;
}

int main(){
    // Binary Search
    double l = 1, r = 1e20;
    while(l<r){
        double mid = (l+r)/2;
        force = 6700000*mid;
        if(force>g(8400*mid+aMass, d)) r = mid;
        else l = mid;
        if(abs(l-r)<1) break;
    }
    cout << l << endl;
    // flag = 1;
    // f(l);
    // printf("Initial Mass: %lf\n", l);
    // printf("Time needed: %lf", t);
    // printf("Initial Velocity: %lf\nInitial Mass: %lf\nTime Needed: %lf", vel, rMass, t);
    return 0;
}