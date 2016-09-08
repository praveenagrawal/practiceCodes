#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0;grid_i < n;grid_i++)
       cin >> grid[grid_i];
    for(int i=1;i<n-1;i++)
   	{
   		for(int j=1;j<n-1;j++)
		{
			if(grid[i-1][j]!='X' && grid[i][j]>grid[i-1][j] && grid[i][j]>grid[i+1][j] && grid[i][j]>grid[i][j+1] && grid[i][j-1]!='X' &&  grid[i][j]>grid[i][j-1])
				grid[i][j]='X';
		}
   	}
   	for(int i=0;i<n;i++)
   		cout<<grid[i]<<endl;
    return 0;
}
