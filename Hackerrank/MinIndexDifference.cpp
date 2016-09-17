#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int M = 20004;

int main() {
    int n;
    cin>>n;
    vector <int> A(n);
    vector <int> B(n);
    vector <int> C(M,-1);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        C[A[i]+10000] = i;
    }
    cin>>B[0];
    int minDiff = C[B[0]+10000];
    int minNum = B[0];
    for(int i=1;i<n;i++)
    {
        cin>>B[i];
        if(abs(C[B[i]+10000]-i)<minDiff)
        {
            minDiff = abs(C[B[i]+10000]-i);
            minNum = B[i];
        }
        else if(abs(C[B[i]+10000]-i)==minDiff)
            minNum = (B[i]<minNum)?B[i]:minNum;
    }
    cout<<minNum;
    return 0;																																				
}

