#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits.h>
using namespace std;

struct tupleK
{
	int k;
	double x;
	double y;
	double z;
};


void merge(std::vector<tupleK> &A, int s, int mid, int e)
{
	int n1 = mid-s+1;
	int n2 = e-mid;
	std::vector<tupleK> L(n1);
	std::vector<tupleK> R(n2);
	for(int i=0;i<n1;i++)
		L[i]=A[s+i];
	for(int i=0;i<n2;i++)
		R[i]=A[mid+1+i];
	tupleK temp;
	temp.k=0;temp.z=0;temp.y=0;temp.z=INT_MIN;
	L.push_back(temp);
	R.push_back(temp);
	int i=0;int j=0;
	for(int k=s;k<=e;k++)
	{
		if(L[i].z>=R[j].z)
			A[k]=L[i++];
		else
		{
			A[k]=R[j];
			j++;
		}
	}
}

void mergeSort(std::vector<tupleK> &A, int s, int e)
{
	if(s<e)
	{
		int mid = (s+e)/2;
		mergeSort(A, s, mid);
		mergeSort(A, mid+1, e);
		merge(A, s, mid, e);
	}
}

void bLargest(std::vector<tupleK> &A, int b)
{
	int n = A.size();
	for(int i=0;i<b;i++)
	{
		int maxIndex = i;
		for(int j=i+1;j<n;j++)
		{
			if(A[j].z>A[maxIndex].z)
				maxIndex = j;
		}
		tupleK temp = A[i];
		A[i] = A[maxIndex];
		A[maxIndex] = temp;
	}
}

void nextLargest(std::vector<tupleK> &A, int b)
{
	int n = A.size();
	int maxIndex = b-1,i;
	for(i=b;i<n;i++)
	{
		if(A[i].z>A[maxIndex].z)
			maxIndex = i;
	}
	tupleK temp = A[b-1];
	A[b-1] = A[maxIndex];
	A[maxIndex] = temp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,b;
    cin>>n>>b;
    std::vector<tupleK> A(n);
    for(int i=0;i<n;i++)
	{
		cin>>A[i].k>>A[i].x>>A[i].y>>A[i].z;
	}
	//mergeSort(A, 0, n-1);
	bLargest(A,b);
	string s;
	while(!cin.eof())
	{
		char q;
		int k;
		cin>>q>>k;
		if(q=='F' || q=='f')
		{
			int i;
			for(i=0;i<b;i++)
			{
				if(A[i].k==k)
				{
					cout<<k<<" = ("<<fixed<<setprecision(3)<<A[i].x<<","<<fixed<<setprecision(3)<<A[i].y<<","<<fixed<<setprecision(3)<<A[i].z<<")\n";
					break;
				}
			}
			if(i==b)
				cout<<"Point doesn't exist in the bucket.\n";
		}
		else
		{
			int i;
			for(i=0;i<b;i++)
			{
				if(A[i].k==k)
				{
					if(A.size()>b)
					{
						A.erase(A.begin()+i);
						cout<<"Point id "<<k<<" removed.\n";
						nextLargest(A,b);
						break;
					}
					else if(A.size()==b)
					{
						cout<<"No more points can be deleted.\n";
						break;
					}
				}
			}
			if(i==b)
				cout<<"Point doesn't exist in the bucket.\n";
		}
	}

    return 0;
}
