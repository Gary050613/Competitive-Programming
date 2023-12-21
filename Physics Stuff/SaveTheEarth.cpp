#include <bits/stdc++.h>
using namespace std;
// double rMass = 100000, vel = 4.32e8, d = 984000000, t = 0;
double G = 6.67e-11, M = 5.97e24, R = 6371000;
double GM = G*M;
// Loses 2578 kg of mass for 6770000 N of thrust each second
double rMass = 48343508610, vel = -130, d = 984000000, t=0, aMass = 3.323e11;
double nOfT = 57;
double force = 6700000*nOfT; // F = ma

// GMm/r/r

double g(double m, double r){
    return GM/r/r*m;
}

int main(){
    while(d <= 984000000){
        t += 1.0;
        if(rMass > 8400*nOfT){
            vel += (force-g(rMass+aMass, d))/(rMass+aMass);
            rMass -= 2578*nOfT;
        }else{
            vel += (-1*g(rMass+aMass, d))/(rMass+aMass);
        }
        d += vel;
        if(d <= 6371000) {break;}
    }
    printf("Final Velocity: %lf\nFinal Mass: %lf\nTime Needed: %lf", vel, rMass, t);
    return 0;
}