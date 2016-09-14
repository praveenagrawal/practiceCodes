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
		int m,n;
		cin>>m>>n;
		int M = 20001;
		std::vector<int> cost(n);
		std::vector<int> temp(M+1,0);
		for(int i=0;i<n;i++)
		{
			cin>>cost[i];
			temp[cost[i]]++;
		}
		int n1=0,n2=0;
		for(int i=1;i<=M;i++)
		{
			if(temp[i]!=0 && temp[m-i]!=0)
			{
				for(int j=0;j<n;j++)
				{
					if(cost[j]==i && n1==0)
						n1=j+1;
					if(cost[j]==m-i && j+1!=n1 && n2==0)
						n2=j+1;
				}
				break;
			}
		}
		cout<<min(n1,n2)<<" "<<max(n1,n2)<<endl;

	}
    return 0;
}
