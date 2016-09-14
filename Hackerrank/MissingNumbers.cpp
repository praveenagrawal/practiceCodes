#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int M = 101;
    int n;
    cin>>n;
    std::vector<int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	int m;
	cin>>m;
	std::vector<int> B(m);
	for(int i=0;i<m;i++)
		cin>>B[i];
	int minB=B[0];
	for(int i=1;i<m;i++)
	{
		if(B[i]<minB)
			minB=B[i];
	}
    std::vector<int> freqA(M, 0);
	std::vector<int> freqB(M, 0);
	for(int i=0;i<n;i++)
		freqA[A[i]-minB]++;
	for(int i=0;i<m;i++)
		freqB[B[i]-minB]++;
	for(int i=0;i<M;i++)
	{
		if(freqB[i]>freqA[i])
			cout<<minB+i<<" ";
	}	
    return 0;
}
