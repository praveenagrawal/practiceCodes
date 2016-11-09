#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int purchase(int n, ull k, int b, std::vector<ull> &result)
{
	if(n<0)
		return -1;
	if(b==1)
	{
		if(k>=n && n>0)
		{
			result.push_back(n);
			return 1;
		}
		else 
			return -1;
	}
	if((n==0 && b>0) || (n>0 && b==0) || (n>0 && b>0 && k==0))
		return -1;
	int status1, status2=-1;
	if(n>=k)
	{
		status1 = purchase(n-k, k-1, b-1, result);
		if(status1==1)
			result.push_back(k);
	}
	else
		status1 = purchase(n, n, b, result);
	if(status1==-1 && n>=k)
	{
		status2 = purchase(n,k-1,b,result);
	}
	if(status1==1 || status2 == 1)
	{
		return 1;
	}
	else
		return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		ull n, k, b;
		cin>>n>>k>>b;
		std::vector<ull> result;
		int status = purchase(n,k,b,result);
		if(status==-1)
			cout<<-1;
		else
		{
			int i;
			for(i=0;i<result.size()-1;i++)
				cout<<result[i]<<" ";
			cout<<result[i];
		}
		if(t!=0)
			cout<<endl;
	}
    return 0;
}
