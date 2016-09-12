#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    int l = s.length();
    int r = floor(sqrt(l));
    int c = ceil(sqrt(l));
    if(r*c<l)
    	r++;
    std::vector<string> grid(r);
    for(int i=0;i<r;i++)
	{
		int t;
		if(l-i*c>=c)
			t=c;
		else
			t = l-i*c;
		grid[i] = s.substr(i*c, t);
	}
	for(int j=0;j<c;j++)
	{
		for(int i=0;i<r;i++)
		{
			if(j<grid[i].length())
			{
				cout<<grid[i][j];
			}
		}
		cout<<" ";
	}

    return 0;
}
