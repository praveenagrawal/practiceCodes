#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool myFunc(int i, int j)
{
	return i>j;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    std::vector<int> cost(n);
    int result = 0;
    int sumC = 0;
    for(int i=0;i<n;i++)
	{
    	cin>>cost[i];
    	sumC+=cost[i];
	}
	sort(cost.begin(), cost.end(), myFunc);
    if(n<=k)
    	result = sumC;
    else
	{
		int j = 1;
		for(int i=0;i<n;i++)
		{
			result+=j*cost[i];
			if((i+1)%k==0)
				j++;
		}
	}
	cout<<result;
    return 0;
}
