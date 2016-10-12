#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,m;
    cin>>n>>m;
	std::vector<unsigned long long> A(n,0);
	while(m--)
	{
		int a,b,k;
		cin>>a>>b>>k;
		a--;
		b--;
		A[a]+=k;
		if(b+1<n)
			A[b+1]-=k;
	}
	unsigned long long maxA = A[0];
	for(int i=1;i<n;i++)
	{
		A[i] = A[i]+A[i-1];
		if(A[i]>maxA)
			maxA = A[i];
	}
	cout<<maxA;
    return 0;
}
