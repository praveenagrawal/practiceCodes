#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int l,b;
		for(l = sqrt(N);l>0;l--)
		{
			if(N%l==0)
			{
				b = N/l;
				cout<<(b-l)<<endl;
				break;
			}
		}
	}
}