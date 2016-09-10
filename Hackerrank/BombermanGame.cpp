#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void printGrid(vector<vector <int> > & grid, int r, int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(grid[i][j]!=0)
				cout<<'O';
			else
				cout<<'.';
		}
		cout<<endl;
	}
}

void fillAll(vector<vector <int> > & grid, int r, int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(grid[i][j]==0)
				grid[i][j]=3;
			else
				grid[i][j]--;
		}
	}
}

int finalState(vector<vector <int> > & grid, int r, int c, int n)
{
	if(n<=1)
		return 1;
	else if(n%2==0)
		fillAll(grid, r, c);
	else
	{
		for(int t=1;t<=n;t++)
		{
			if(t%2==0)
				fillAll(grid, r, c);
			else
			{	
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{					
					if(grid[i][j]==1)
					{
						grid[i][j] = 0;
						if(i!=0)
							grid[i-1][j] = 0;
						if(i!=r-1 && grid[i+1][j]!=1)
							grid[i+1][j] = 0;
						if(j!=0)
							grid[i][j-1] = 0;
						if(j!=c-1 && grid[i][j+1]!=1)
							grid[i][j+1] = 0;
					}
					else if(grid[i][j]==2 || grid[i][j]==3)
						grid[i][j]--;
				}
			}
			}
		}
	}
	return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int r,c;
    long long n;
    cin>>r>>c>>n;
    vector<vector <int> > grid(r, std::vector<int> (c));
    string s;
    for(int i=0;i<r;i++)
	{
    	cin>>s;
    	for(int j=0;j<c;j++)
    	{
    		if(s[j]=='.')
    			grid[i][j]=0;
    		else
    			grid[i][j]=3;
    	}
	}
	if(n>=9 && n%2!=0)
	{
		if((n-7)%4==0)
			n=7;
		else if((n-5)%4==0)
			n=5;
	}
    finalState(grid, r, c, n);
    printGrid(grid, r, c);
    return 0;
}
