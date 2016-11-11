#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(std::vector<int> &A, int k)
{
	int n= A.size();
	int l=0, r=n, m;
	while(r-l>1)
	{
		m = (l+r)/2;
		if(A[m]<=k)
			l = m;
		else
			r = m;
	}
	if(A[l]==k) return l;
	else return -1;
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
		cout<<binarySearch(A,k)<<endl;
	}
	return 0;
}