#include <iostream>
#include <vector>
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

bool searchMatrix(vii &A, int x)
{
	int n = A.size();
	int m = A[0].size();
	int i = 0, j = m-1;
	while(i<n && j>=0)
	{
		if(A[i][j]==x)
			return 1;
		if(A[i][j]>x)
			j--;
		else
			i++;
	}
	return 0;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vii A(n, vi(m));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>A[i][j];
		}
		int x;
		cin>>x;
		cout<<searchMatrix(A, x)<<endl;
	}
	return 0;
}