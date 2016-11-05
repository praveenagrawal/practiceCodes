#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,a,b;
		cin>>n>>a>>b;
		int result = 0;
		int countA=0, countB=0;
		while(a!=0)
		{
			countA+=(a%2);
			a/=2;
		}
		while(b!=0)
		{
			countB+=(b%2);
			b/=2;
		}
		if(countA+countB<=n)
		{
			for(int i =n-1;i>=n-(countB+countA);i--)
				result+=pow(2,i);
			cout<<result<<endl;
		}
		else
		{
			for (int i = n-1; i >=(countA+countB)-n; i--)
				result+=pow(2,i);
			cout<<result<<endl;
		}
	}
}