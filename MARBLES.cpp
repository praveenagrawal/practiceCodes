#include <iostream>
#include <vector>
using namespace std;

unsigned long long C(int n, int r)
{
	if(r>n/2)
		r = n-r;
	unsigned long long ans = 1;
	for(int i=1;i<=r;i++)
	{
		ans*= n-r+i;
		ans/= i;
	}
	return ans;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n, k;
		cin>>n>>k;
		int freeSpace = n-k;
		if(freeSpace == 0)
			cout<<'1'<<endl;
		else
		{
			int limit = (k<freeSpace)?k:freeSpace;
			unsigned long long total = 0;
			total = k;
			for(int t = 2; t<=limit;t++)
			{
				total+= C(k,t)*C(n-k-1,t-1);
				//cout<<C(k,t)*C(n-k-t-1,n-k-t)<<endl;
			}
			cout<<total<<endl;
		}
	}
}