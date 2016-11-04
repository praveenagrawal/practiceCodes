#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back

int ceilIndex(vector <int> &table, int l, int r, int num)
{
    int m;
    while(r-l>1)
    {
        m = (r+l)/2;
        if(table[m]>=num )
            r = m;
        else
            l = m;
    }
    return r;
}

int lcs(vector <int> &A, int n)
{
    vector <int> table(n,0);
    int length = 1;
    table[0]=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]<table[0])
            table[0] = A[i];
        else if(A[i]>table[length-1])
            table[length++] = A[i];
        else
            table[ceilIndex(table, -1, length-1, A[i])] = A[i];
    }
    return length;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    vector <int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<lcs(A, n);
    return 0;
}
