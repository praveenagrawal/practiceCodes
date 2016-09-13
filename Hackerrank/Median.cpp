#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int> &A, int s, int e)
{
	int x = A[e];
	int j=s;
	for(int i=s;i<e;i++)
	{
		if(A[i]<=x)
			swap(A[j++],A[i]);
	}
	swap(A[j], A[e]);
	return j;

}
int selectA(vector<int> &A, int s, int e, int k)
{
	if(s==e)
		return A[s];
	int q = partition(A,s,e);
	int l = q-s+1;
	if(l==k)
		return A[q];
	else if (k<l)
		return selectA(A,s,q-1,k);
	else
		return selectA(A,q+1,e,k-l);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<int> A(n);
    for(int i=0;i<n;i++)
    	cin>>A[i];
    cout<<selectA(A, 0, n-1, n/2 + 1);
    return 0;
}
