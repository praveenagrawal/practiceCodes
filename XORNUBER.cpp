#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int k=1,can=0;
		if(n==1)
		{
			cout<<2<<endl;
			continue;
		}
		while(pow(2,k)-1<=n)
		{
			if(pow(2,k)-1==n)
				can=1;
			k++;
		}
		if(can==0)
			cout<<-1<<endl;
		else
		{
			n = n>>1;
			cout<<n<<endl;
		}
	}	
}