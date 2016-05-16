#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N,X;
	string s;
	cin>>X>>N;
	int count = 0;
	while(N--)
	{
		cin>>s;
		for(int i=0;i<=8;i++)
		{
			int temp = 0;
			for(int j=0;j<=3;j++)
			{
				if(s[4*i + j]=='0')
					temp++;
			}
			if(s[53-(2*i)]=='0')
				temp++;
			if(s[53-(2*i)-1]=='0')
				temp++;
			if(temp>=X)
			{
				int tempCount1 = 1, tempCount2 = 1;
				for(int j=1;j<=X;j++)
				{
					tempCount1*=temp;
					temp--;
					tempCount2*=j;
				}
				count+=tempCount1/tempCount2;
			}
		}
	}
	cout<<count<<endl;
}