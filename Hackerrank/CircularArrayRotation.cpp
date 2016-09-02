#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
int main() 
{
    // Enter your code here. Read input from STDIN. Print output to STDOUT 
	int n,k,q;
	cin>>n>>k>>q;
	std::vector<int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int l=0;l<k;l++)
	{
		int temp = A[n-1];
		for(int i=n-1;i>0;i--)
			A[i] = A[i-1];
		A[0] = temp;
	}    
	while(q--)
	{
		int m;
		cin>>m;
		cout<<A[m]<<endl;
	}
    return 0;
}
*/
int main() 
{
    // Enter your code here. Read input from STDIN. Print output to STDOUT 
	int n,k,q;
	cin>>n>>k>>q;
	k = k%n;
	std::vector<int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	std::vector<int> stackA(k);
	for(int i=0;i<k;i++)
		stackA[i] = A[n-k+i];
	for(int i=n-1;i>=k;i--)
		A[i] = A[i-k];
	for(int i=0;i<k;i++)
		A[i] = stackA[i];

	while(q--)
	{
		int m;
		cin>>m;
		cout<<A[m]<<endl;
	}
    return 0;
}