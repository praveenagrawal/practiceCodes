#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		int count = 0, temp = 0;
		for(int j = 0;j<s.length();j++)
		{
			if(s[j]=='<')
				temp++;
			else
				temp--;
			if(temp==0)
				count = j+1;
			if(temp<0)
				break;
		}
		cout<<count<<endl;
	}
}