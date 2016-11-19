#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef std::vector<int> vi;

int numTriangles(vi &A)
{
	int count = 0;
	int n = A.size();
	sort(A.begin(), A.end());
	for(int i=0;i<n-2;i++)
	{
		int k = i+2;
		for(int j=i+1;j<n-1;j++)
		{
			while(A[k]<(A[i]+A[j]) && k<n)
				k++;
			count+= k-j-1;
		}
	}
	return count;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<numTriangles(A)<<endl;
	}
	return 0;
}