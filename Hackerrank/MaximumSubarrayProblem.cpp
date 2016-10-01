#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

/*unsigned long long findMaxCrossingSubArray(std::vector<unsigned long long> &A, int low, int mid, int high, unsigned long long m)
{
	unsigned long long leftSum = 0;
	unsigned long long sum = 0;
	for(int i=mid; i>=low; i--)
	{
		sum = (sum+A[i])%m;
		if(sum>leftSum)
			leftSum = sum;
	}
	unsigned long long rightSum = 0;
	sum = 0;
	for(int i=mid+1;i<=high;i++)
	{
		sum = (sum+A[i])%m;
		if(sum>rightSum)
			rightSum = sum;
	}
	return (leftSum+rightSum)%m;
}

unsigned long long findMaxSubArray(std::vector<unsigned long long> &A, int low, int high, unsigned long long m)
{
	unsigned long long leftSum , rightSum, crossSum;
	if(high==low)
		return A[low]%m;
	else
	{
		int mid = (low+high)/2;
		leftSum = findMaxSubArray(A, low, mid, m);
		rightSum = findMaxSubArray(A, mid+1, high, m);
		crossSum = findMaxCrossingSubArray(A, low, mid, high, m);
		if(leftSum>=rightSum && leftSum>=crossSum)
			return leftSum;
		else if(rightSum>=leftSum && rightSum>=crossSum)
			return rightSum;
		else
			return crossSum;
	}
}*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    long double a;
    cin>>q;
    while(q--)
	{
		int n;
		unsigned long long m;
		cin>>n>>m;
		std::vector<unsigned long long> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		std::vector<unsigned long long> prefix(n);
		prefix[0] = A[0]%m;
		for(int i=1;i<n;i++)
			prefix[i] = (prefix[i-1]+A[i])%m;

	}
    return 0;
}
