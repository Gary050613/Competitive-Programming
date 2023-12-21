#include <bits/stdc++.h>
using namespace std;
double G = 6.67e-11, M = 5.97e24, R = 6371000;
double GM = G*M;
double vel = 0, d = R, t=0;
double nOfT = 570000000;
// double rMass = 48343508610;
double force = 6700000*nOfT; // F = ma

double g(double m, double r){
    return GM/r/r*m;
}
double f(double m){
    vel = 0, d = R, t=0;
    double rMass = m;
    while(d <= 984000000){  
        t += 1.0;
        if(rMass - 2578*nOfT >= 48343508610){
            vel += (force-g(rMass, d))/(rMass);
            rMass -= 2578*nOfT;
        }else{
            return -1;
        }
        d += vel;
        printf("Current Velocity: %lf\n", vel);
        printf("Current Distance: %lf\n", d);
        if(d<R) return -1;
    }
    return rMass;
}
int main(){
    double l = 48343508610, r = 1e20;
    while(l<r){
        double mid = (l+r)/2;
        if(f(mid)>48343508610) r = mid;
        else l = mid;
        if(abs(l-r)<1) break;
    }
    cout << l << endl;
    return 0;
}