#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    while(q--)
	{
		int n;
		cin>>n;
		std::vector<std::vector<int> > A(n, std::vector<int> (n));
		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
			{
				int a;
				cin>>a;
				if((i<n && j<n))
					A[i][j] = a;
				else if(i>=n && j>=n)
				{
					if(a>=A[2*n-1-i][2*n-1-j])
						A[2*n-1-i][2*n-1-j] = a;
				}
				else if(i>=n && j<n)
				{
					if(a>=A[2*n-1-i][j])
						A[2*n-1-i][j] = a;
				}
				else if(i<n && j>=n)
				{
					if(a>=A[i][2*n-1-j])
						A[i][2*n-1-j] = a;
				}
			}
		}
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				sum+=A[i][j];
		}
		cout<<sum<<endl;
	}
    return 0;
}
