#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  double pi = 0;
  for(int i=1;i<=1000000000;i++){
    pi += 1.0/i/i;
  }
  pi = sqrt(6.0*pi);
  printf("%.10lf\n",pi);
}