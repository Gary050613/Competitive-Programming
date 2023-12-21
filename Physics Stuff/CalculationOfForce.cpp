#include <bits/stdc++.h>
using namespace std;
// double rMass = 100000, vel = 4.32e8, d = 984000000, t = 0;
double G = 6.67e-11, M = 5.97e24, R = 6371000;
double GM = G*M;
// Loses 2578 kg of mass for 6770000 N of thrust each second
double vel = -130, d = 984000000, t=0, aMass = 3.323e11;
double nOfT;
double force = 6700000*nOfT; // F = ma

// GMm/r/r
bool flag=1;
double g(double m, double r){
    // double a = M/r/r*G*M*m;
    return GM/r/r*m;
}
double f(double m){
    vel = -130, d = 984000000, t=0, aMass = 3.323e11; double rMass = m;
    while(d <= 984000000){  
        t += 1.0;
        if(rMass > 8400*nOfT){
            vel += (force-g(rMass+aMass, d))/(rMass+aMass);
            rMass -= 2578*nOfT;
        }else{
            vel += (-1*g(rMass+aMass, d))/(rMass+aMass);
        }
        d += vel;
        // if(rMass <= 100000) break;
        if(flag && vel > 0){printf("Closest: %lf\n", d); flag = 0;}
        // if(d <= 6371000) {printf("You hit the Earth at %.0lfs!\n", t);break;}
        if(d <= 6371000) {return -1;}
    }
    return rMass;
}
double g(double n){
    nOfT=n;
    force = 6700000*n;
    double l = 1e5, r = 1e12;
    while(l<r){
        double mid = (l+r)/2;
        if(f(mid)==-1) l = mid+1;
        else r = mid;
        if(abs(l-r)<1) break;
    }
    if(abs(r-1e12)<100) return -1;
    else return r;
}
double cost(double n){
    // unit of millions
    int a = g(n);
    if(a==-1) return -1;
    return n*15+a*0.000000120;
}
int main(){
    // Binary Search
    double l = 57;
    // for(int i=100;i>=1;i--){
    //     if(cost(i)==-1){cout << i+1 << endl; break;}
    // }
    // cout << cost(l) << endl;
    printf("Initial Mass: %lf\n", g(l));
    printf("Cost: %lf million dollars\n", cost(l));
    // nOfT = r;
    // cout << g(l) << endl;
    // force = 6700000*nOfT;
    // cout << f(1e12) << endl;;
    // while(l<r){
    //     double mid = (l+r)/2;
    //     if(cost(mid)>cost(mid-1)) r = mid-1;
    //     else l = mid;
    //     if(abs(l-r)<1) break;
    // }
    // cout << r << endl;
    // f(l);
    // printf("Initial Velocity: %lf\nInitial Mass: %lf\nTime Needed: %lf", vel, rMass, t);
    return 0;
}