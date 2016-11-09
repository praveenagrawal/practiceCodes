#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct cost
{
	unsigned long long c;
	bool dim;
};

bool myFunc(cost i, cost j)
{
	return i.c>j.c;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		int m,n;
		cin>>m>>n;
		std::vector<cost> cList(n+m-2);
		int i=0;
		for(int j=0;j<m-1;j++)
		{
			cin>>cList[i].c;
			cList[i].dim = 0;	// y-axis
			i++;
		}
		for(int j=0;j<n-1;j++)
		{
			cin>>cList[i].c;
			cList[i].dim = 1;
			i++;
		}		
		sort(cList.begin(), cList.end(), myFunc);

		unsigned long long cutX = 1, cutY = 1;
		unsigned long long minCost = 0;
		for(int i=0;i<n+m-2;i++)
		{
			if(cList[i].dim)
			{
				cutX++;
				minCost = (minCost + cutY*cList[i].c);
			}
			else
			{
				cutY++;
				minCost = (minCost + cutX*cList[i].c);
			}
		}
		cout<<minCost%1000000007<<endl;
		cList.clear();
	}
    return 0;
}
