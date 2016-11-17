#include <iostream>
#include <vector>

using namespace std;

int findK(std::vector<std::vector<int> > &A, int n, int m, int k)
{
	if(k==1)
		return A[0][0];
	int i=0, j=1,l=3;
	int vl=n-1, hl=m-1;
	int direction = 1;	// 1-> right , 2-> down, 3-> left, 4->up
	if(m==1)
	{
		i=1;j=0;
		direction = 2;
	}
	for(int count=2;count<k;count++)
	{
		if(direction==1)
		{
			if(j<hl)
				j++;
			else if(j==hl)
			{
				direction = 2;
				i++;
			}
		}
		else if(direction==2)
		{
			if(i<vl)
				i++;
			else if(i==vl)
			{
				direction = 3;
				j--;
			}
		}
		else if(direction==3)
		{
			if(j>m-1-hl)
				j--;
			else if(j==m-1-hl)
			{
				direction = 4;
				i--;
				vl--; hl--;
			}
		}
		else
		{
			if(i>n-1-vl)
				i--;
			else
			{
				direction = 1;
				j++;
			}
		}
	}
	return A[i][j];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		std::vector<std::vector<int> > A(n, std::vector<int> (m));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>A[i][j];
		}
		cout<<findK(A, n, m, k)<<endl;
	}
}