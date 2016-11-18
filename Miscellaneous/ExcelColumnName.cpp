#include <iostream>
using namespace std;

string columnName(unsigned int n)
{
	string result = "";
	while(n>0)
	{
		unsigned d = n%26;
		if(d==0)
		{
			result = 'Z'+result;
			n = n/26 - 1;
		}
		else
		{
			char ch =  'A'+d-1;
			result = ch+ result;
			n=n/26;
		}
	}
	return result;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned int n;
		cin>>n;
		cout<<columnName(n)<<endl;
	}
	return 0;
}