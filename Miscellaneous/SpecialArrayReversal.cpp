#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s, temp;
		cin>>s;
		temp = s;
		int n = s.size();
		int i=0, j=n-1;
		while(i<=j)
		{
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
			{
				if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z'))
				{
					char ch = s[i];
					s[i] = s[j];
					s[j] = ch;
					i++; j--;
				}
				else
					j--;
			}
			else
				i++;
		}
		cout<<s<<endl;
	}
}