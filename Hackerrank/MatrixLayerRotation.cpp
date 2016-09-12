#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,n,R;
    cin>>m>>n>>R;
    std::vector<vector<int> > grid(m , vector<int> (n));
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>grid[i][j];
	}
	for(int l=0;l<min(m,n)/2;l++)
	{
		int numOfElements = 2*(m-2*l) + 2*((n-2*l)-2);
		int r = R % numOfElements;
		std::vector<int> temp;
		int j=l,i;
		for(i=l;i<m-l-1;i++)
			temp.push_back(grid[i][j]);
		for(j=l;j<n-l-1;j++)
			temp.push_back(grid[i][j]);
		for(i=m-l-1;i>l;i--)
			temp.push_back(grid[i][j]);
		for(j=n-l-1;j>l;j--)
			temp.push_back(grid[i][j]);

		std::vector<int> stackA(r);
		for(i=0;i<r;i++)
			stackA[i] = temp[numOfElements-r+i];
		for(i=numOfElements-1;i>=r;i--)
			temp[i] = temp[i-r];
		for(i=0;i<r;i++)
			temp[i] = stackA[i];

		j=l; int count = 0;
		for(i=l;i<m-l-1;i++)
			grid[i][j] = temp[count++];
		for(j=l;j<n-l-1;j++)
			grid[i][j] = temp[count++];
		for(i=m-l-1;i>l;i--)
			grid[i][j] = temp[count++];
		for(j=n-l-1;j>l;j--)
			grid[i][j] = temp[count++];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}

    return 0;
}
