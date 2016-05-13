#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int T,N,count;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>N;
		cin>>s;
		count = 0;
		vector <int> status(N,1);
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='1')
			{
				status[i]=0;
				if(i==0)
					status[i+1]=0;
				else if(i==N-1)
					status[i-1]=0;
				else
				{
					status[i-1]=0;
					status[i+1]=0;
				}
			}
		}
		for(int i=0;i<N;i++)
		{
			if(status[i]==1)
				count++;
		}
		cout<<count<<endl;
	}
}