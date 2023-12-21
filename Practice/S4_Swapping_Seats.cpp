#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
string input;
int N, A, B, C, pA[MM], pB[MM], pC[MM], ans=INT_MAX;
int main(){
    cin >> input;
    N = input.length();
    for(int i=0;i<N;i++){
        if(input[i]=='A') A++, pA[i+1]++;
        if(input[i]=='B') B++, pB[i+1]++;
        if(input[i]=='C') C++, pC[i+1]++;
    }
    for(int i=1;i<=N;i++){
        pA[i] += pA[i-1];
        pB[i] += pB[i-1];
        pC[i] += pC[i-1];
    }
    // Formula = B in A + C in A + max(B in C, C in B)
    for(int i=1;i<=N;i++){
        // if A starts at i, B starts at (i+A-1)%N+1, C starts at (i+A+B-1)%N+1
        // A B C
        int j = (i+A-1)%N+1;
        int k = (i+A+B-1)%N+1;
        // B in A = pB[j-1]-pB[i-1]
        int BinA, CinA, BinC, CinB;
        if(j-1<i-1){BinA = pB[j-1]+pB[N]-pB[i-1]; CinA = pC[j-1]+pC[N]-pC[i-1];}
        else BinA = pB[j-1]-pB[i-1], CinA = pC[j-1]-pC[i-1];
        // BinC = pB[i-1]-pB[k-1]
        if(i-1<k-1) BinC = pB[i-1] + pB[N] - pB[k-1];
        else BinC = pB[i-1]-pB[k-1];
        // CinB = pC[k-1]-pC[j-1]
        if(k-1<j-1) CinB = pC[k-1] + pC[N] - pC[j-1];
        else CinB = pC[k-1]-pC[j-1];
        ans = min(ans, BinA+CinA+max(BinC, CinB));
        k = (i+A+C-1)%N+1;
        if(j-1<i-1){BinA = pB[j-1]+pB[N]-pB[i-1]; CinA = pC[j-1]+pC[N]-pC[i-1];}
        else BinA = pB[j-1]-pB[i-1], CinA = pC[j-1]-pC[i-1];
        if(i-1<k-1) CinB = pC[i-1] + pC[N] - pC[k-1];
        else CinB = pC[i-1]-pC[k-1];
        if(k-1<j-1) BinC = pB[k-1] + pB[N] - pB[j-1];
        else BinC = pB[k-1]-pB[j-1];
        ans = min(ans, BinA+CinA+max(BinC, CinB));
    }
    cout << ans << endl;
    return 0;
}