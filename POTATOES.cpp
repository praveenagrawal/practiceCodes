#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int z = 1;
		int sum = x+y+z;
		for(int i=2;i<=sum/2;i++)
		{
			if(sum%i==0)
			{
				sum++;
				z++;
				i=2;
			}
		}
		cout<<z<<endl;
	}
}