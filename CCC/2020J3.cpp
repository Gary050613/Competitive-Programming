#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, a, b, blx = 101, bly = 101, maxx = 0, maxy = 0;
  scanf("%d",&n);
  while(n--){
    scanf("%d,%d", &a, &b);
    blx = min(blx, a);
    bly = min(bly, b);
    maxx = max(maxx, a);
    maxy = max(maxy, b);
  }
  printf("%d,%d\n%d,%d", blx-1, bly-1, maxx+1, maxy+1);

	return 0;
}


