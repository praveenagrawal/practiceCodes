#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void countingSort(vector<int> &A, vector<int> &B, int M)
{
	std::vector<int> C(M,0);
	for(int i=0;i<A.size();i++)
		C[A[i]]++;
	for(int i=1;i<M;i++)
		C[i]+=C[i-1];
	for(int i=A.size()-1;i>=0;i--)
		B[--C[A[i]]] = A[i];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<int> A(n);
    for(int i=0;i<n;i++)
    	cin>>A[i];
    int M=100;
    std::vector<int> B(n);
    countingSort(A, B, M);
    for(int i=0;i<A.size();i++)
		cout<<B[i]<<" ";
    return 0;
}
