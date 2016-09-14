#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

void merge(std::vector<int> &A, int s, int mid, int e, unsigned long long &count)
{
	int n1 = mid-s+1;
	int n2 = e-mid;
	std::vector<int> L(n1);
	std::vector<int> R(n2);
	for(int i=0;i<n1;i++)
		L[i]=A[s+i];
	for(int i=0;i<n2;i++)
		R[i]=A[mid+1+i];
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);
	int i=0;int j=0;
	for(int k=s;k<=e;k++)
	{
		if(L[i]<=R[j])
			A[k]=L[i++];
		else
		{
			A[k]=R[j];
			if(i<n1)
			count+=(mid+1+j-k);
			j++;
		}
	}
}

void mergeSort(std::vector<int> &A, int s, int e, unsigned long long &count)
{
	if(s<e)
	{
		int mid = (s+e)/2;
		mergeSort(A, s, mid, count);
		mergeSort(A, mid+1, e, count);
		merge(A, s, mid, e, count);
	}
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
		unsigned long long count = 0;
		mergeSort(A,0,n-1,count);
		cout<<count<<endl;
	}
    return 0;
}
