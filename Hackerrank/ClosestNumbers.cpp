#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(std::vector<int> &A)
{
	int n=A.size();
	for(int i=1;i<n;i++)
	{
		int key = A[i];
		int j=i-1;
		while(j>=0 && A[j]>key)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    std::vector<int> A(n);
    for(int i=0;i<n;i++)
    	cin>>A[i];
    insertionSort(A);
    std::vector<int> closest;
    int minA = abs(A[0]-A[1]);
    for(int i=0;i<n-1;i++)
	{
		if(abs(A[i]-A[i+1])<minA)
		{
			minA = abs(A[i]-A[i+1]);
			closest.clear();
			closest.push_back(A[i]);
			closest.push_back(A[i+1]);
		}
		else if(abs(A[i]-A[i+1])==minA)
		{
			closest.push_back(A[i]);
			closest.push_back(A[i+1]);
		}
	}
	for(int i=0;i<closest.size();i++)
		cout<<closest[i]<<" ";
    return 0;
}
