#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		ull n, k, b;
		cin>>n>>k>>b;
		ull minSum = (b*(b+1))/2;
		ull maxSum = ((k*(k+1))/2) - (((k-b)*(k-b+1))/2);
		if(n<minSum || n>maxSum)
		{
			cout<<-1;
			if(t!=0)
				cout<<endl;
			continue;
		}
		ull temp = n-minSum;
		ull temp2;
		temp2 = temp/b;
		int r = temp%b;
		int i;
		for(i=1;i<b;i++)
		{
			if(r==0)
				cout<<i+temp2<<" ";
			else
			{
				if(i>b-r)
					cout<<i+temp2+1<<" ";
				else
					cout<<i+temp2<<" ";
			}
		}
		if(i>b-r)
			cout<<i+temp2+1;
		else
			cout<<i+temp2;
		if(t!=0)
			cout<<endl;
	}
    return 0;
}
