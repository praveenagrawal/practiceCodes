#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		int n;
		cin>>n;
		std::vector<string> grid(n);
		bool result = true;
		for(int i=0;i<n;i++)
		{
			std::vector<int> count(26,0);
			cin>>grid[i];
			for(int j=0;j<n;j++)
				count[grid[i][j]-'a']++;
			int l=0;
			for(int j=0;j<26;j++)
			{
				for(int k=0;k<count[j];k++)
				{
					grid[i][l] = 'a'+j;
					l++;
				}
			}
		}
		for(int i=1;i<n && result;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(grid[i][j]<grid[i-1][j])
				{
					result = false;
					break;
				}
			}
		}
		if(result)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}
