#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<string> grid(n);
    for(int i=0;i<n;i++)
    	cin>>grid[i];
    int r=0;
    for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(grid[i][j]=='.')
			{
				int t=1; int done = false;
				for(t=1;t<=n/2 + 1 && !done;t++)
				{
					if(i+t<n && i-t>=0 && j+t<n && j-t>=0)
					{
						if(grid[i+t][j]!='.' || grid[i-t][j]!='.' || grid[i][j+t]!='.' || grid[i][j-t]!='.')
						{
							done = true;
							break;
						}
						int k=1,l=1;
						for(k=1;k<=t && !done;k++)
						{
							for(l=1;l<=t && !done;l++)
							{
								if(k*k + l*l <=t*t)
								{
									if(i+k<n && i-k>=0 && j+l<n && j-l>=0)
									{
										if(grid[i+k][j+l]!='.' || grid[i-k][j-l]!='.' || grid[i+k][j-l]!='.' || grid[i-k][j+l]!='.')
										{
											done = true;
											break;
										}
									}
									else break;
								}
								else
									break;
							}
						}
					}
					else 
						break;
					if(done)
						break;
				}
				if(--t>r)
					r=t;
			}
		}
	}
	cout<<r;
    return 0;
}
