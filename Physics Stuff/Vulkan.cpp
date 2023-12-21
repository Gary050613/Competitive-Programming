#include <iostream>
#include <cmath>
using namespace std;
double diameter = 13584000, population = 7000000000, dis = 2000000;
double radius = diameter/2, interval = 1, v=0, totalTime=0;
double t, acc, fVelocity;
// g = Gm/r^2
double g = 9.81, G = 6.67e-11; double surfAcc = 1.4*g;
// Mass of Vulkan can be rertrieved from the information of surface gravity
double GM = surfAcc * radius * radius;
int main(){
    // Time the matter takes to reach the surface Vulkan
    while(dis > 0){
        // Calculate acceleration at specific location
        acc = GM/(dis+radius)/(dis+radius);
        // Calculate final velocity after travelling 1 meter
        fVelocity = sqrt(v*v+2*acc*interval);
        // Calculate Time to proceed 1 meter (If Statement to avoid Runtime Error)
        t = (fVelocity-v)/acc;
        v = fVelocity;
        totalTime += t;
        dis -= interval;
// I just realised how much easier it is to just do the calculation with increments of seconds...
    }
    // Time the matter takes to reach the core
    acc = surfAcc;
    double twerkPerM = surfAcc/radius;
    while(radius > 0){
        acc -= twerkPerM;
        
        radius -= interval;
    }
    cout << totalTime << endl;
    return 0;
}