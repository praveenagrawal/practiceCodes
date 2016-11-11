#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findIndex(std::vector<int> &A, int l, int r, int k)
{
	if(l>r) return -1;
	int m = (l+r)/2;
	if(A[m]==k) return m;
	if(A[l]<=A[m])
	{
		if(A[l]<=k && A[m]>=k)
			return findIndex(A, l, m-1, k);
		else return findIndex(A, m+1, r, k);
	}
	else if(A[m]<=A[r])
	{
		if(A[m]<=k && A[r]>=k)
			return findIndex(A, m+1, r, k);
		else return findIndex(A, l, m-1, k);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		std::vector<int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		int k;
		cin>>k;
		cout<<findIndex(A, 0, n-1, k)<<endl;
	}
}