#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

void merge(std::vector<int> &A, int s, int mid, int e)
{
	int n1 = mid-s+1;
	int n2 = e-mid;
	std::vector<int> L(n1);
	std::vector<int> R(n2);
	for(int i=0;i<n1;i++)
		L[i]=A[s+i];
	for(int i=0;i<n2;i++)
		R[i]=A[mid+1+i];
	L.push_back(INT_MIN);
	R.push_back(INT_MIN);
	int i=0;int j=0;
	for(int k=s;k<=e;k++)
	{
		if(L[i]>=R[j])
			A[k]=L[i++];
		else
		{
			A[k]=R[j];
			j++;
		}
	}
}

void mergeSort(std::vector<int> &A, int s, int e)
{
	if(s<e)
	{
		int mid = (s+e)/2;
		mergeSort(A, s, mid);
		mergeSort(A, mid+1, e);
		merge(A, s, mid, e);
	}
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    std::vector<int> P(n);
    std::vector<int> D(n);
    std::vector<int> Q(n);
    long long profit = 0;
    for(int i=0;i<n;i++)
	{
		cin>>P[i]>>D[i];
		Q[i] = P[i]+D[i];
        profit-=D[i];
	}
    if(k>=n)
	{
		for(int i=0;i<n;i++)
			profit+=P[i]+D[i];
		cout<<profit;
		return 0;
	}
	mergeSort(Q, 0, n-1);
	for(int i=0;i<k;i++)
	{
		profit+=Q[i];
	}
	if(profit>0)
		cout<<profit;
	else
		cout<<0;

    return 0;
}