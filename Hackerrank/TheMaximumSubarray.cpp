#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*long long findMaxCrossingSubArray(std::vector<int> &A, int low, int mid, int high)
{
	long long leftSum = 0;
	long long sum = 0;
	for(int i=mid; i>=low; i--)
	{
		sum+= A[i];
		if(sum>leftSum)
			leftSum = sum;
	}
	long long rightSum = 0;
	sum = 0;
	for(int i=mid+1;i<=high;i++)
	{
		sum+= A[i];
		if(sum>rightSum)
			rightSum = sum;
	}
	return (leftSum+rightSum);
}

long long findMaxSubArray(std::vector<int> &A, int low, int high)
{
	long long leftSum , rightSum, crossSum;
	if(high==low)
		return A[low];
	else
	{
		int mid = (low+high)/2;
		leftSum = findMaxSubArray(A, low, mid);
		rightSum = findMaxSubArray(A, mid+1, high);
		crossSum = findMaxCrossingSubArray(A, low, mid, high);
		if(leftSum>=rightSum && leftSum>=crossSum)
			return leftSum;
		else if(rightSum>=leftSum && rightSum>=crossSum)
			return rightSum;
		else
			return crossSum;
	}
}*/

long long findMaxSubArray(std::vector<int> &A)
{
	int n = A.size();
	long long currentMax = A[0];
	long long maxSoFar = A[0];
	for(int i=1;i<n;i++)
	{
		currentMax = (A[i]>currentMax+A[i])?A[i]:currentMax+A[i];
		maxSoFar = (maxSoFar>currentMax)?maxSoFar:currentMax;
	}
	return maxSoFar;
}

long long findMaxSum(std::vector<int> &A)
{
	long long maxSum = A[0];
	int n= A.size();
	for(int i=1;i<n;i++)
	{
		if(A[i]>0 && maxSum>=0)
			maxSum+= A[i];
		else if(maxSum<=0 && A[i]>maxSum)
			maxSum = A[i];
	}
	return maxSum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		std::vector<int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		long long max1 = findMaxSubArray(A);
		long long max2 = findMaxSum(A);
		//long long max1 = findMaxSubArray(A, 0, n-1);
		//long long max2 = findMaxSubSequence();
		cout<<max1<<" "<<max2<<endl;
	}
    return 0;
}
